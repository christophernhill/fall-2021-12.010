! gfortran -fcoarray=lib x.F90 -lcaf_openmpi
! mpirun -n 2 ./a.out
program hello_world
implicit none
  integer :: scalar[*]
  integer :: i
  write(*,*) 'Hello world from ', &
   this_image() , 'of', num_images()
  scalar[this_image()] = this_image()
  if ( this_image() .eq. 1 ) then
    do i=1,num_images()
      write(*,*) 'Image: ',i,', scalar:',scalar[i]
    enddo
  endif
end program hello_world
