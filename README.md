# jigsaw-lock
An image-based authentication system on a touch screen, image is broken down into blocks, user select some blocks. Every time the user tries to login, the image will be broken down and shuffled randomly. Correct selection of blocks will provide access to the system. C data structures improved code readability. The purpose is to provide security with images instead of using normal alphanumeric passwords.

Author:Shweta Satyasheel Mane 

Files:
* main.c: This file consists the main logic as follows:
            1)The touch screen into several sections
            2)The whole user account setup
            3)Password saving
            4)The re-login screen
            5)The password re-entry match process
            6)Providing/denying access
            GOL library is used extensively to create buttons, text entry boxes and direction keys.
            
Apart from this extensive support is needed for interacting with the touch screen/lcd, creating graphic objects. All this is available from MLA files available on the PIC website.

* images of the sample block image used in the project as password.
* video of the project.
