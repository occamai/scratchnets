


import types

import ml_dtypes


class BFloat16Storage:
    dtype = ml_dtypes.bfloat16
    nbytes = 2

def _rebuild_tensor_v2(a,b,c,d,e,f):
    '''Stub for the pickled pytorch call.'''
    #print("rebuild!",a,b,c,d,e,f)
    tensor = a.reshape(c)
    return tensor

torch = types.ModuleType("torch")
print(torch, dir(torch))

torch.BFloat16Storage = BFloat16Storage
print(torch.BFloat16Storage)

torch._rebuild_tensor_v2 = _rebuild_tensor_v2
print(torch._rebuild_tensor_v2)
