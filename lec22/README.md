# iap-2021-12.091

# Directory of MPI example for 1d diffusion equation.

Files: 

 - __diffusion1d.ipynb__
 
    A simple serial example of 1d diffusion equation for starting creating an
    MPI equivalent. Creation of MPI counterpart is shown in the files step1.py - 
    step6.py.
 
 - __step1.py__
 
    Illustrates using mpi4py Python package for MPI, and creating multiple
    MPI ranks running on several processes.
 
 - __step2.py__
 
    Adds code that illustrates basic message sending between ranks using
    MPI. 


 - __step3.py__
 
    Introduces code that divides the indices of a global vector into
    local blocks of indices split over ranks with halo.
 
 - __step4.py__
 
   Introduces send and receive of halo region for a divided vector. 
 
 - __step5.py__
 
  Initializes a distributed array based on global spatial coordinate that each MPI 
  rank is working on.
 
 - __step6.py__

 Add in time-stepping loop that computes time derivatives and updates halo points at
 each time step. 
 
# To run on TXE1

  - Download code from gtihub from login node
    ```
    login-2$ git clone https://github.com/christophernhill/iap-2021-12.091.git
    ```
    
  - To run serial code in __diffusion1d.ipynb__ 
  
    Runs within notebook after installing python celluloid package.
    
    For now, to install celluloid, do this once.
    1. Open terminal from within notebook
    2. from terminal login to front end node e.g. `ssh login-2`
    3. on login node run the following two commands
          ```
             module load anaconda/2020b
             pip install --user celluloid
          ```
          
  - To run parallel MPI codes (__step1.py__ - __step6.py__)
  
    1. From login node start an interactive session, for example
       ```
       login-2:~$ srun -N 2 -n 20 -I --pty /bin/bash
       ```
       
        or
        
       ```
       login-2:~$ LLsub -i -N 2 -n 20
       ```
       
       either of the above commands will request a session with two physical nodes and 20 total
       _task slots_. The task slots will be divided evenly between the nodes 
       so that an MPI program will created 10 ranks on each node by default. 
       
    2. From within interactive session
    
       ```
       module load anaconda/2020b
       module load mpi
       mpirun ./step1.py
       ```
       
  - Example of parallel run
   
   ```
   login-2$ srun -N 2 -n 20 -I --pty /bin/bash   
   d-12-16-2$ module load anaconda/2020b
   d-12-16-2$ module load mpi
   d-12-16-2$ mpirun ./step1.py
I am rank    0 of 20 executing on d-12-16-2
I am rank    2 of 20 executing on d-12-16-2
I am rank    3 of 20 executing on d-12-16-2
I am rank    4 of 20 executing on d-12-16-2
I am rank    5 of 20 executing on d-12-16-2
I am rank    6 of 20 executing on d-12-16-2
I am rank    7 of 20 executing on d-12-16-2
I am rank    8 of 20 executing on d-12-16-2
I am rank    9 of 20 executing on d-12-16-2
I am rank    1 of 20 executing on d-12-16-2
I am rank   10 of 20 executing on d-13-1-1
I am rank   11 of 20 executing on d-13-1-1
I am rank   12 of 20 executing on d-13-1-1
I am rank   13 of 20 executing on d-13-1-1
I am rank   14 of 20 executing on d-13-1-1
I am rank   15 of 20 executing on d-13-1-1
I am rank   16 of 20 executing on d-13-1-1
I am rank   17 of 20 executing on d-13-1-1
I am rank   18 of 20 executing on d-13-1-1
I am rank   19 of 20 executing on d-13-1-1

   ```
          
  
   
