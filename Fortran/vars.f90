  program vars

! Program to show some features of variables in fortran
! Many of the techinques used here are not good programming
! practice.

  implicit none
  
! Define some generic type variables
  integer*4 i, j, k
  real*4    r04_1, r04_2
  real*8    r08_1, r08_2   ! Definitions of single variables
  real*8    r08_a(10)  !10 element array
  real*8    r08_b(2,3) ! A 2-row, 3-column matrix
  
  complex*8 c08_1  ! A complex variable (real and imaginary)
  
  logical*4 l04_1, l04_2   ! Logical
  
  character*32 string
  
!    Tests  ******
! See what happen when we pass these variables and constants into
! into subroutine
! First fill the arrays
  do i =1,10
     r08_a(i) = dble(i)
  end do
  do i = 1, 2
     do j = 1, 3
    r08_b(i,j) = dble(i)*1000.d0 + dble(j)
     end do
  end do

! Now pass these arrays into subroutines and see what happens
! Correct passage:
  call var_sub_01(j, r08_a, r08_b)
  
  print *,'Return from var_sub_01 ',j

! In this call, we have changed the dimensioning inside the
! subroutine.
  
  call var_sub_02(j, r08_a, r08_b)
  print *,'Return from var_sub_02 ',j
  
! In this call, we have the correct dimensioning but we have
! changed the variable types
  
  call var_sub_03(j, r08_a, r08_b)
  print *,'Return from var_sub_03 ',j
  
  end
  
!TITLE VAR_SUB_01

  subroutine var_sub_01(n, d1, d2)

! Test 01: correct declaration of variables
!
  implicit none

! PASSED VARIABLES  
  integer*4 n
  real*8 d1(10), d2(2,3)
  
! LOCAL VARIABLES
  integer*4 i,j
  
!***  Write out the values that have been passed.
  write(*,100)
100  format(/,'VARS: Test 01: Correct declaration of arrays. Type and dimension correct')
  write(*,110) (i,d1(i), i=1,10)
110  format('Array1: ',10(i3,F8.2))
  write(*,120) ((i,j,d2(i,j), i=1,2),j=1,3)
120  format('Array 2: ',10(i3,i3,F8.2))
 
! Set a return value
  n = 10
 
!***  Thats all
  return
  end
   
!TITLE VAR_SUB_02

  subroutine var_sub_02(n, d1, d2)

! Test 02: Change the declaration but keep the type 
! the same (you should not do this)
!
  implicit none

! PASSED VARIABLES  
  integer*4 n
  real*8 d1(2,5), d2(6)
  
! LOCAL VARIABLES
  integer*4 i,j
  
!***  Write out the values that have been passed.
  write(*,100)
100  format(/,'VARS: Test 02: In correct declaration of arrays', &
              ' Type correct, dimension incorrect')
  write(*,110) ((i,j,d1(i,j), i=1,2),j=1,5)
110  format('Array 1: ',10(i3,i3,F8.2))
  write(*,120) (i,d2(i), i=1,6)
120  format('Array 2: ',10(i3,F8.2))
 
! Set a return value
  n = 11
   
!***  Thats all
  return
  end
   
!TITLE VAR_SUB_03

  subroutine var_sub_03(n, d1, d2)

! Test 03: correct dimensions, but wrong type
!
  implicit none

! PASSED VARIABLES  
  integer*4 n
  real*4 d1(10), d2(2,3)
  
! LOCAL VARIABLES
  integer*4 i,j
  
!***  Write out the values that have been passed.
  write(*,100)
100  format(/,'VARS: Test 01: correct dimensioning ', &
              ' but type is wrong.')
  write(*,110) (i,d1(i), i=1,10)
110  format('Array1: ',10(i3,F8.2))
  write(*,120) ((i,j,d2(i,j), i=1,2),j=1,3)
120  format('Array 2: ',10(i3,i3,F8.2))
 
! Set a return value
  n =12
 
!***  Thats all
  return
  end
           
                   
