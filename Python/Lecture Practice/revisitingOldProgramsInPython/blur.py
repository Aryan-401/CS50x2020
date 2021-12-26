from PIL import Image, ImageFilter

before = Image.open("images/courtyard.bmp")
after = before.filter(ImageFilter.BoxBlur(10))
after.save("out.bmp")