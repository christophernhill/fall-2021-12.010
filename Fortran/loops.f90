  program loops

      implicit none

!     Program to demonstrate use of loops in fortran
!    (Lines that start with * or C are comments; all code starts in
!     at least column 7 and can't go past 72 in general)
!

!**** START OF PROGRAM *****
! Non-executable statements
!     Declare variables first
      integer*4  i, j    ! This is a comment, i and j loop variables
      integer, dimension(10,10) :: iarray
      logical done       ! Logical variable type

! Start of excutable statements

!***  Output what this program does
      write(*,100) 
 100  format('Program to demonstrate loops')

!***  Standard loop
      write(*,200)
 200  format('Standard do loop',/, &
             '   I   I**2 ')         ! This is a continuation line
!    This loop loops from 1 to 10 increments of 1.  We could use
!     integer variables instead of 1 and 10 e.g.
!     n = 1
!     m = 10
!     do i = n, m   ! is the equivalent code
!     do i = m, n, -1  ! count down instead of up.
      do i = 1, 10
         ! Could add a cycle commnd.
         ! if( i > 3 .and. i < 5 ) cycle
         ! Could add an exit command
         ! if( i > 5 ) exit
         write(*,210) i,i**2
 210     format(1x,i3,1x,i6)
      end do

!***  Do while loop
!     The other loop is a do while loop which is useful if the
!     bounds are not known.  (See inout.f)
      write(*,220)
 220  format('Output from do while loop',/,'   I   I**2 ')        
      done = .false.
      i = 0
      do while ( .not. done )
         i = i + 1
         if( i.ge.10 ) done = .true.
         write(*,210) i,i**2     ! Notice here we use the earlier format
      end do

!     Fortran 90 also allows the forall construction
      print *,'FORALL ARRAY Initialization'
      iarray = -1   ! Initialize the array with -1 values
      forall ( i=1:10 , j = 1:10 , j<i )
         iarray(i,j) = i*j
      end forall
      write(*,'(10(I4,1x))') iarray

  end



