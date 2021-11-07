import sounddevice as sd
from scipy.io.wavfile import write

import argparse

fs = 16000  # Sample rate
seconds = 1  # Duration of recording
print("Start Recording")
myrecording = sd.rec(int(seconds * fs), samplerate=fs, dtype='int16', channels=1)
sd.wait()  # Wait until recording is finished
print("Stop Recording")
write('output.wav', fs, myrecording)  # Save as WAV file