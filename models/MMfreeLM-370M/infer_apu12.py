
import os
import traceback
os.environ["TOKENIZERS_PARALLELISM"] = "false"
print("GW MAIN before mmfreelm")
import mmfreelm
print("GW MAIN after mmfreelm")

from transformers import AutoModelForCausalLM, AutoTokenizer
print("GW MAIN after transformers")

#Change here to our open-sourced model
name = 'ridger/MMfreeLM-370M'

tokenizer = AutoTokenizer.from_pretrained(name)
print("GW MAIN after tokenizer")

input_prompt = "In a shocking finding, scientist discovered a herd of unicorns living in a remote, "
input_ids = tokenizer(input_prompt, return_tensors="pt").input_ids.cuda()
#GW CPU input_ids = tokenizer(input_prompt, return_tensors="pt").input_ids
print("GW MAIN input_ids=", input_ids)

print("GW MAIN before model")
model = AutoModelForCausalLM.from_pretrained(name).cuda().half()
#GW CPU model = AutoModelForCausalLM.from_pretrained(name, device_map='cuda:0').half()
print("GW MAIN after model=", model)

try:
    outputs = model.generate(input_ids, max_length=32,  do_sample=True, top_p=0.4, temperature=0.6)
    print("GW MAIN after outputs=", outputs)
except:
    print("MAIN ERROR!!!")
    print(traceback.format_exc())
#print(tokenizer.batch_decode(outputs, skip_special_tokens=True)[0])

print("GW MAIN END")
