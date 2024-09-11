

TODO:
* yikes having trouble reproducing the exact "pirate" output...fix this!
* clean up print statements in notebooks
* implement sampling of softmax probabilites instead of argmax (like what transformer library does)
* figure out the pytorch vs HF weights mismatch (it seems to also be affecting the output quality)
* implement decode stop by checking for 'end' token
* implement KV cache
* figure out numpy MPS backend support
* figure out float32 upcasting issue with ml_types' implementation of bfloat16
* integrate various RAG techniques
* implement LORA adapter fine-tuning
* revert to using HF safe tensors (instead of the custom HF export)
* unit tests (like trivial inputs)
