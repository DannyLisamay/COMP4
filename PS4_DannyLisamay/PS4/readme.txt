/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Danny Lisamay 
Partner: Dheera Vuppala
Login:

Hours to complete assignment: 6-7

/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
In thie program we comapred two string such as a DNA sequence. We created 2 
Vectors that took in two string from a text file. Twos two strings were 
used to for our ED (Edit Distance) class. Using our problem, we comapred 
each char in each Vector and created a matrix. 

Using the example equation.
opt[i][j] = min { opt[i+1][j+1] + 0/1, opt[i+1][j] + 2, opt[i][j+1] + 2 }

We calcualted the cost of each elemnt if the matrix;
Gap = 2
Mismatch =1
Same =0

In the [0][0] postion of the matrix was the least cost of the distance.

Next we recored the path that was taken to recieve the min cost and printed the 
solution.

/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Doesn't work. Correctly

Input:

Expected output: many outputs

What happened: segmentation core dump



/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2 GB to 16 GB.
 **********************************************************************/
16 GB


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limitedto 8GB (billion bytes) of memory?
 **********************************************************************/
Class ED contains
3 ints Methods
1 string Method

2 char Vectors

a = 3
b = N ^ 2 
largest N = 51639.77

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
 *  Answer yes, no, I didn't try, I tried and failed, or I used a 
 *  different tool.
 *
 *  If yes, paste in the ms_print top chart of memory use over time,
 *  and also indicate which file your code was solving.
 * 
 *  Explain if necessary.
/**********************************************************************
Yes, we were able to run Valgrind. 
ecoli28284.txt
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 66 112,548,113,079    7,416,747,120    7,416,520,737       226,383            0


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       118            0.107177           41.188528
ecoli5000.txt       160            0.616625           164.218088
ecoli7000.txt       194            1.09245            459.376465
ecoli10000.txt      223            2.62042            1311.85896
ecoli20000.txt      3135           10.0088            5245.079952
ecoli28284.txt      8394           19.2465            7416.747120

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
N = 4(MB)
1 Sec = 450(MB)
86400 Sec = day
450(MB) *Day = 4/(Largest N)
largest N = 9720000

/
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where (describe a method or provide a lines numbers)
 **********************************************************************/
Used lamda expression, insted of penalty and min class methods.
line 21 -26
    auto lambdaPenalty=[](char a, char b) { 
        if(a==b)return 0;
        return 1; 
    };

    auto lambdaMin=[](int a, int b, int c){
        if(a <= b && a <= c) return a;
        if(b <= a && b <= c) return b;
        return c;
    };



**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
Worked as pair.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Couldnt get endgaps7 to work. Also mem and time calc.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Used lambda expression for extra credit.