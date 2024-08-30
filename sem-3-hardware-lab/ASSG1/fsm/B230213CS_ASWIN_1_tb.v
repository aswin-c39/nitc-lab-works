module B230213CS_ASWIN_1_tb;
	
	reg clk, rst_n, data;
	wire seq_detected;
	
	B230213CS_ASWIN_1 uut(
		.clk(clk),
		.rst_n(rst_n),
		.data(data),
		.seq_detected(seq_detected)
	);
	
	always begin
		#5
		clk = ~clk;
	end
	
	
	initial begin
		clk = 0;
		rst_n = 0;
		data = 0;
		
		#10 rst_n = 1;
		
		#10 data = 1;
		#10 data = 1;
		#10 data = 0;
		#10 data = 1;
		#10 data = 0;
		
		#10 data = 1;
		#10 data = 0;
		#10 data = 1;
		#10 data = 1;
		#10 data = 0;
		
		#10 data = 1;
		#10 data = 1;
		#10 data = 1;
		#10 data = 0;
		#10 data = 1;
		#10 data = 0;
		
		#10 data = 0;
		#10 data = 0;
		#10 data = 0;
		
		#20 $finish;
	end

	initial begin
		$monitor("Time: %0d | data = %b | seq_detected = %b | cur_state = %b",$time,data,seq_detected, uut.cur_state);
	end
endmodule
