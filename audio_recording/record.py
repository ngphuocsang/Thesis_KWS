import sounddevice as sd
from scipy.io.wavfile import write
import sys


fs = 16000  # Sample rate
seconds = 1  # Duration of recording
print("Start Recording")
myrecording = sd.rec(int(seconds * fs), samplerate=fs, dtype='int16', channels=1)
sd.wait()  # Wait until recording is finished
print("Stop Recording")
write('./{word}/output.wav'.format(word = sys.argv[1]), fs, myrecording)  # Save as WAV file