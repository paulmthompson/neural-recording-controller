Both the OpenEphys acquisition board and the RHD/RHS Recording Controllers from Intan internally use Opal Kelly FPGAs to 
run the Intan headstages, as well as other acquisition hardware, like digital inputs and outputs. 
  
The original C3100 from Intan (which is now discontinued) used XEM6010-LX45 FPGA, which is USB2.0 and now in end of life:  
https://opalkelly.com/products/xem6010/  
  
The oldest Open Ephys boards also used this. The RHD Controller and next generation Open Ephys acquisition boards both used 
the XEM6310-LX45, which is now also at end of life:  
https://opalkelly.com/products/xem6310/  
This device is USB3.0 instead of USB2.0  

I do not have one, but I believe the newest Intan RHD controllers use this drop in replacement FPGA from Opal Kelly, the XEM7310-A75:  
https://opalkelly.com/products/xem7310/  

The stimulation acquisition board from Intan (RHS Recording Controller) uses the USB2.0 XEM6010-LX45, but may have been upgraded.  
  
All of these boards will utilize the FrontPanel library to communicate via usb with the FPGA in a cross platform way. What the FPGA 
is doing under the hood will depend on the content of the bitfile uploaded to it.