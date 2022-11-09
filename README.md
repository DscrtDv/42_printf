# PRINTF
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
![status-production](https://user-images.githubusercontent.com/92900172/200838158-75ca174d-d12c-489a-bf78-6b310fd7d54b.svg)
![code-by-dscrtdv](https://user-images.githubusercontent.com/92900172/200837083-3fe44953-8c00-49be-9837-a2abb5437ea6.svg)

Simplified re-implementation of printf.

## Content

Printf functions | Others
:----------- | ------------: |
ft_printf.c   |   libft/
num_utils.c   |   ft_printf.h
type_handler.c|   Makefile

### Conversions
+ %c: prints a single character.
+ %s: prints a string.
+ %p: prints void pointer in Hexadecimal format
+ %d: prints decimal number.
+ %i: prints decimal number.
+ %u: prints unsigned decimal number.
+ %x: prints decimal in hexadecimal number (abcdef)
+ %X: prints decimal in hexadecimal number (ABCDEF)
+ %%: prints a percent sign.

# Use

```
git clone https://github.com/DscrtDv/Printf_42.git
cd Printf_42
make
```

**This repository comes with a Makefile**
+ make: builds the whole project into an archive.
+ make clean: deletes all object files.
+ make fclean: makes clean and deletes archive file.
+ make norm: *use if you have norminette installed* usefull for 42 student following to norm rules applied by Norminette.

## Submodules in this repository

+ libft: https://github.com/DscrtDv/Libft_42

## Author
Discret Dev
