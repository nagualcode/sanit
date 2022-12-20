
▟▛ ▞▚ ▛▟ █ ▜▛ 

#### Video Demo
[https://youtu.be/MaVSDMhaIHI](https://youtu.be/MaVSDMhaIHI)

#### Description

## TLDR:
Sanit is a tool that will revolutionize the way you organize your files! With just one simple command, you can say goodbye to those pesky special characters that always seem to cause problems.

## Introduction:

Hello everyone!

I am excited to present my first C program, which I wrote after taking the CS50 course. This program is a command line utility that renames all the files in a directory by replacing any special characters or whitespaces in their names with underscores.

I believe that this tool can be really useful for people who want to clean up their file names and remove any potential problems that may arise from using special characters.

## How the code works

Here is a brief explanation of how the code works: 
- It first opens the directory and reads all its entries using the `readdir` function. 
- For each entry, it copies the file name to the `old_name` buffer and replaces any special characters or whitespaces in the name with underscores, storing the modified name in the `new_name` buffer. 
- If the `new_name` is different from the `old_name`, the program checks if there is already a file with the same name as the `new_name` using the `access` function. 
- If there is, it adds an underscore to the beginning of the `new_name` until it becomes unique. 
- Finally, the program renames the file using the `rename` function and prints the old and new filenames to the console.

## Future improvements

In the future, I would like to add some nice features to this program, such as:
- The ability to specify the directory to be renamed
- The ability to pass individual filenames as arguments
- The option to exclude certain files or file types from being renamed
- Improved error handling

I hope you find this program useful and I look forward to hearing your feedback and suggestions for improvement, don't exitate to fork in on github!

Thanks for tuning in, and a special thanks to CS50 for giving me the will to try to code in C. So, what are you waiting for? Give Sanit a try and see the difference it can make in your file organization!

## How To Compile:
```
 make sanit
```

## Github
[github](https://github.com/nagualcode/sanit)
