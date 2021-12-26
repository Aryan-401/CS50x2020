from cs50 import get_string
import re

words = get_string("Text: ").lower()
letter = len(re.findall('[a-zA-Z]', words))
word = len(words.split());
sentence = len(re.findall(r'[.!?]+', words))


lphw = (letter * 100) / word
sphw = (sentence * 100) / word

read = round(0.0588 * lphw - 0.296 * sphw - 15.8, 0)
if read > 16:
    print('Grade 16+')
elif read < 1:
    print("Before Grade 1")
else:
    print(f"Grade {int(read)}")
# print(letter, len(word), len(sentence)-1)
