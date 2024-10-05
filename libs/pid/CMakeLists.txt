# Create a library called "myLib2" (in Linux, this library is created
# with the name of either libmyLib2.a or myLib2.so).
add_library (myPID
  # list of cpp source files:
  PIDImpl.cpp
  )

# Indicate what directories should be added to the include file search
# path when using this library.
target_include_directories(myPID PUBLIC
  # list of directories:
  .
  )
