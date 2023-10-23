# jpeg

- It is actually a compression format.
- Lossy compression.
- Container for the file format is JFIF or EXIF.
- JFIF is mutually incompatible with the EXIF format.
- Has distinct SOI (start of image) and EOI (end of image).
- Any image viewer checks the EOI and stops reading the image at that point. So you can have any data appended at the end of it. For linux it is as simple as `echo $DATA >> file.jpg`
