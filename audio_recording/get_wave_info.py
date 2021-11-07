import wave
file = 'output.wav'
f= wave.open(file, mode='rb')
print(f.getframerate())
print(f.getsampwidth())
print(f.getnchannels())