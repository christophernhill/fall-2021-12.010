 program ifs

      implicit none

!     Program to demonstate if statements.

!     Declarations
      integer*4 i, j
      integer*4 ierr    ! Error when reading from screen
      logical result
      character*80 line

!**   Use some simple input to get value
      line = 'Program to demonsrate if statements'
      write(*,'(a)') line    ! Demonstrates another way to output

!***  Ask the user for a value
      write(*,'(a)') 'Enter two values between 1 and 10'
      read(*,*) i,j

!***  Output values from user
      write(*,100) i,j
 100  format('User input values ',I3,' and ',i3)

!     See if error generated on read (! used for comment, so /- for NE)
      if( ierr /= 0 ) then   ! If error is not zero
         write(*,200) ierr
 200     format('IOSTAT Error ',i5,' occurred reading i and j')
         print *,'Values ',i,j
!        If this is servere we could uncomment line below
!        stop 'Error reading i and j'
      endif

!***  Now test the values.  Notice the indenting (not needed but
!     good to allow easy reading of code).
      if( i.gt.10 .and. j.gt.10 ) then
          print *,'User gave values too large'
      elseif( i.lt.1 .and. j.le.0 ) then 
!         Notice in line above that test is the same for i and j 
!         (because they are integer)
          print *,'User gave values too small'
      elseif( i.lt.1 .or. i.gt. 10 ) then
          print *,'User gave invalid value of I'
      elseif( j.le.0 .or. j.ge. 11 ) then
          print *,'User gave invalid value of J'
      else
          write(*,'(a)') 'Users input was good'
          if( i.gt.j ) then
             write(*,310) i,i-j
 310         format('I=',i3,' is greater than J. Difference is ',i3)
          else
             write(*,320) J,i-j
 320         format('J=',i3,' is greater than or equal I. Difference is ',i3)
          endif
      endif

 end




