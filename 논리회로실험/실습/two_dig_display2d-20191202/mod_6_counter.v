module mod_6_counter (clk, rst, cnt);
  input     		clk, rst;
  output	[2:0]	cnt;
  reg   	[2:0]	cnt;

	always @(posedge clk) begin
		if (rst) cnt <= 0;
		else begin
			if (cnt == 5) cnt <= 0;
			else	     cnt <= cnt + 1;
		end
	end

endmodule
