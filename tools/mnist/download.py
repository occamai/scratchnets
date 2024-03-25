import torch
import torchvision
import torchvision.datasets as datasets

print("torch version=",torch.__version__)

print("Downloading...")
datasets.MNIST(root='./data', train=True, download=True, transform=None)

print("Done.")
