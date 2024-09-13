import transformers
import torch
import sys

model_id = "meta-llama/Meta-Llama-3.1-8B-Instruct"

pipeline = transformers.pipeline(
  "text-generation",
  model="meta-llama/Meta-Llama-3.1-8B-Instruct",
  model_kwargs={"torch_dtype": torch.bfloat16},
  device="cpu",
)

messages = [
    {"role": "system", "content": "You are a pirate chatbot who always responds in pirate speak!"},
    {"role": "user", "content": "Who are you?"}
]

#outputs = pipeline(
#    messages,
#    max_new_tokens=256
#)

prompt = ['''<|begin_of_text|><|start_header_id|>system<|end_header_id|>\n\n'''
             '''Cutting Knowledge Date: December 2023\nToday Date: 26 Jul 2024\n\n'''
             '''You are a pirate chatbot who always responds in pirate speak!'''
             '''<|eot_id|><|start_header_id|>user<|end_header_id|>\n\n'''
             '''Who are you?<|eot_id|><|start_header_id|>assistant<|end_header_id|>\n\n''']

outputs = pipeline(
    prompt,
    max_new_tokens=256
)

print(outputs)

sys.exit(0)


