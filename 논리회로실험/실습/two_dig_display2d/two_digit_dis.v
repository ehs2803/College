module two_digit_dis(clk, rst, seg_com, seg_data);

  input		      clk, rst;
  output [7:0]	seg_com, seg_data;

  wire	 [3:0]	cnt_bcd;
  wire    [2:0]   cnt_mod_6;

  reg [7:0]	seg_com, seg_data;
  wire [7:0]	seg_data_1, seg_data_10;

  reg             ten_or_one;

  frq_div10 U19(clk,rst,clk5);
  frq_div10 U20(clk5,rst,clk6);
  frq_div10 U21(clk6,rst,clk7);
  bcd_counter U0 (clk7, rst, cnt_bcd);
  
  
  frq_six U25(clk6,rst,clk61);
  mod_6_counter U1(clk61, rst, cnt_mod_6);
  
  bcd_to_seg_mod U3 (cnt_bcd,seg_data_1);
  bcd_to_seg_mod U4 (cnt_mod_6,seg_data_10);
  
  
  always @ (posedge clk) begin
		if (!ten_or_one) begin
			seg_data <= seg_data_1;
			seg_com <= 8'b0111_1111;
		end
		else begin
			seg_data <= seg_data_10;
			seg_com <= 8'b1011_1111;
		end
		ten_or_one <= ~ten_or_one;
  end

endmodule
