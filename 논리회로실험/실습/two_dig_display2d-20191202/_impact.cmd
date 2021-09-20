setMode -bs
setMode -bs
setCable -port auto
Identify 
identifyMPM 
assignFile -p 2 -file "D:/temp/two_dig_display2/two_digit_dis.bit"
Program -p 2 -defaultVersion 0 
setMode -bs
deleteDevice -position 1
deleteDevice -position 1
setMode -ss
setMode -sm
setMode -hw140
setMode -spi
setMode -acecf
setMode -acempm
setMode -pff
setMode -bs
