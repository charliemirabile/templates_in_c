# templates_in_c
framework for template system like C++ in C. Just a meme—but it does work.
NOTE: there must be a folder called 'templates' inside of the vector_example folder.
It exists to hold all of the programmatically generated template code and .o files. Git cannot
keep an track an empty directory, and by design the make clean rule deletes all the contents of
the templates folder to clean up that programmatically created code, so you must add the folder
yourself by running `mkdir templates` inside of vector_exmaple.
