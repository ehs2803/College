module second_two_digits(clk, rst, clk_min_1, seg_com, seg_data);

  input		      clk, rst;
  output          clk_min_1;
  output [7:0]	seg_com, seg_data;

  reg [7:0]	seg_com, seg_data;
  reg [1:0] ten_or_one;

  wire clk_1hz, clk_digit_10;
  wire [7:0]	seg_data_1, seg_data_10, seg_data_100, seg_data_1000;

  freq_div_N #(1000) U_freq_div_1000 (.clk_in(clk), 
											     .rst(rst), 
											     .clk_div_N(clk_1hz));

  second_1 U_sec_1(.clk_in(clk_1hz), 
						 .rst(rst), 
						 .clk_out(clk_digit_10), 
						 .seg_data(seg_data_1));
  
  second_10 U_sec_10(.clk_in(clk_digit_10), 
						   .rst(rst), 
					   	.clk_out(clk_min_1), 
						   .seg_data(seg_data_10));
							
  second_1 U_min_1(.clk_in(clk_min_1), 
						 .rst(rst), 
						 .clk_out(clk_min_10), 
						 .seg_data(seg_data_100));
						 
  second_10 U_min_10(.clk_in(clk_min_10), 
						   .rst(rst), 
					   	.clk_out(clk_h_1), 
						   .seg_data(seg_data_1000));
    
  always @ (posedge clk) begin
      
		if (ten_or_one==2'b00) begin
			seg_data <= seg_data_1;
			seg_com <= 8'b0111_1111;
		end
		else if(ten_or_one==2'b01) begin
			seg_data <= seg_data_10;
			seg_com <= 8'b1011_1111;
		end
		else if(ten_or_one==2'b10) begin
			seg_data <= seg_data_100;
			seg_com <= 8'b1101_1111;
		end
		else begin
		   seg_data <= seg_data_1000;
			seg_com <= 8'b1110_1111;
		end
		ten_or_one=ten_or_one+1;
  end

endmodule
