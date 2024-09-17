import torch
import sys

#
# quant_weight
#

w = torch.rand((4,4))
print("w=",w)
a = w.abs().mean()
print("a=",a)
scale = 1.0 / w.abs().mean().clamp_(min=1e-5)
print("scale=", scale)
## Quantize and then de-quantize the tensor
rnd =  (w * scale).round()
print("rnd=", rnd)
u = (w * scale).round().clamp_(-1, 1) / scale
print("u=",u)
sys.exit(0)

#
# Test norm_fwd_quant_kernel
#

shape=(2,5)
eps = 1e-08
X = torch.rand(shape)
W = torch.ones((1,shape[1]))
print("X=", X, "W=", W)
 
# pre normalize with projection weights
mx = torch.multiply( X, X )
# print("GW _layer_norm_fwd_1pass_kernel mx=", mx, mx.shape )
sm = torch.sum( mx, dim=1 )
# print("GW _layer_norm_fwd_1pass_kernel sm=", sm, sm.shape )
var = torch.divide( sm, X.shape[1])
# print("GW _layer_norm_fwd_1pass_kernel vardiv=", var, var.shape )
vareps = torch.add(var, eps)
# print("GW _layer_norm_fwd_1pass_kernel vareps=", vareps, vareps.shape )
vsqrt = torch.sqrt( vareps )
# print("GW _layer_norm_fwd_1pass_kernel vsqrt=", vsqrt, vsqrt.shape )
rstd = torch.reciprocal( vsqrt ).reshape( ( vareps.shape[0], 1 ) )
# print("GW _layer_norm_fwd_1pass_kernel rstd=", rstd, rstd.shape, X.shape, ( X.shape[0], X.shape[1]) )
brstd = torch.broadcast_to( rstd, (X.shape[0], X.shape[1]) )
# print("GW _layer_norm_fwd_1pass_kernel brstd=", brstd, brstd.shape )
normalized_hidden_state = torch.mul(X, brstd)
print("GW _layer_norm_fwd_1pass_kernel AFTER INTERNAL NORM hidden_state=", normalized_hidden_state )
Wb = torch.broadcast_to( W, normalized_hidden_state.shape )
print("GW _layer_norm_fwd_1pass_kernel Wb=", Wb )
hidden_state = torch.multiply( Wb, normalized_hidden_state )
print("GW _layer_norm_fwd_1pass_kernel FINAL BEFORE QUANT hidden_state=", hidden_state )
    
# quantize
## scale = 127.0 / tl.maximum(t1.max(tl.abs(y), 0), 1e-5)
abs_ = torch.abs( hidden_state )
print("GW _layer_norm_fwd_1pass_kernel ABS=", abs_ )

D=1
max_ = torch.max( abs_, dim=D, keepdim=True ).values
inds_ = torch.max( abs_, dim=D, keepdim=True ).indices
print("GW _layer_norm_fwd_1pass_kernel MAX=", max_, inds_)

smn_ = torch.FloatTensor([1e-5]).broadcast_to( max_.shape ).broadcast_to( abs_.shape )
print("GW _layer_norm_fwd_1pass_kernel SMN=", smn_ , smn_.shape)
max__ = torch.maximum( max_, smn_)

print("GW _layer_norm_fwd_1pass_kernel MAX__=", max__ )

scale_ = 127.0 / max__
print("GW _layer_norm_fwd_1pass_kernel SC=", scale_ )

# y = tl.math.round(y * scale)

scaled = hidden_state * scale_
print("GW _layer_norm_fwd_1pass_kernel SCALED=", scaled )

rnd_ = torch.round( scaled )
print("GW _layer_norm_fwd_1pass_kernel RND=", rnd_ )

# y = tl.maximum(tl.minimum(y, 127), -128) / scale

lgpn_ = torch.FloatTensor([127]).broadcast_to( max_.shape ).broadcast_to( abs_.shape )
print("GW _layer_norm_fwd_1pass_kernel LGPN=", lgpn_ )

min_ = torch.minimum( rnd_, lgpn_ )
print("GW _layer_norm_fwd_1pass_kernel MIN=", min_ )

lgnn_ = torch.FloatTensor([-128]).broadcast_to( max_.shape ).broadcast_to( abs_.shape )
print("GW _layer_norm_fwd_1pass_kernel LGNN=", lgnn_ )

max_ = torch.maximum( min_, lgnn_ )
print("GW _layer_norm_fwd_1pass_kernel MAX=", max_ )

dqtz_ = max_ / scale_
torch.set_printoptions(profile="full")
print("GW _layer_norm_fwd_1pass_kernel DQTZ=", dqtz_)
torch.set_printoptions(profile="default")

