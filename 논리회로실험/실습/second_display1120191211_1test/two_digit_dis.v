module two_digit_dis(clk, rst, seg_com, seg_data);

  input		      clk, rst;
  output [7:0]	seg_com, seg_data;

  wire	 [3:0]	cnt_bcd;
  wire    [2:0]   cnt_mod_6;

  reg [7:0]	seg_com, seg_data;
  wire [7:0]	seg_data_1, seg_data_10;

  reg             ten_or_one;

  bcd_counter U0 (clk, rst, cnt_bcd);
  mod_6_counter U1(clk, rst, cnt_mod_6);
  
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
