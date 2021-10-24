  program subs

      implicit none

!     Program to show the use of subroutines and functions.
!

      real*8 a,s,c,t  ! Angle, sin, cos, and tan
      real*8 angdeg   ! User defined function below

      real*8 ar       ! Arguments in degrees with cycles

      integer*4 i     ! Simple loop counter

!***  Say what we are going to do
      write(*,110) 
 110  format('Demonstration of subroutines and functions')

      write(*,200) 
 200  format('Ang (rad)  Sin     Cos     Tan Nrot  Ang (deg)')
      do i = 1, 10
         a = i/5.0d0   ! Replace 5.0d0 with just 5 and see what happens
         call trig(a,c,s,t)
         ar = angdeg(s,c,i-5)
         write(*,220) a, s, c, t, i-5, ar
 220     format(F6.2,1x,3(F7.3,1x),1x,i3,1x,F10.2)
      end do

!***  Thats alls
   end


   subroutine trig( ang, cosang, sinang, tanang )

      implicit none

!***  Subroutine to return trig functions given angle

!     Declare the variable passed
      real*8 ang  ! Input angle (radians)
      real*8 cosang, sinang, tanang  ! trig function values

!     Use the intinsic functions to get values
      cosang = cos(ang)
      sinang = sin(ang)
      tanang = tan(ang)

!     Thats all
   end


   real (kind=8) function angdeg( sinang, cosang, nrot )

      implicit none

!     Routine to return angle with nrot cycles added.

!     Use a parameter statement to define PI
      real*8 pi
      parameter ( pi = 3.1415926535897932d0 )  ! d0 at end make double
                                               ! precision

!     Demonstration of a user function
!     Input variables
      real*8 cosang, sinang  ! Input sine and cose angle
      integer*4 nrot         ! Number of rotations to be added.

!     LOCAL VARIABLES (used only here)
      real*8 ang

!***  Get the angle from atan2
      ang = atan2(sinang,cosang)   ! atan2 is instrinsic 

!     Now convert to degrees and add nrot rotations
      angdeg = ang*180.d0/pi + nrot*360.d0

      return   ! Not really need (used to return before end)/
  end


