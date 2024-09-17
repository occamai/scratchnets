
from mmfreelm.models import HGRNBitConfig
from transformers import AutoModel

config = HGRNBitConfig()
print("config=", config)

m = AutoModel.from_config(config)
print(m)


