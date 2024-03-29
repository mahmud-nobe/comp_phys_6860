#!/bin/csh

setenv VEC2D /Users/putschke/Computing/Programs/lec9/Lib
setenv LD_LIBRARY_PATH ${VEC2D}:${LD_LIBRARY_PATH}
setenv DYLD_LIBRARY_PATH ${VEC2D}:${DYLD_LIBRARY_PATH}

if ($?TERM == 0 || $?prompt == 0) exit 0

echo ''
echo 'Setup GSL and ROOT'
echo '====================================='
echo ''
echo "<I>---------------Info--------------------<I>"
echo "Setting up the following environments: "
echo "vec2d " $VEC2D
echo "<I>---------------Info--------------------<I>"
echo ""
