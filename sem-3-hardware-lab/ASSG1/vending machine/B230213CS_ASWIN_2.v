module B230213CS_ASWIN_2(
	input wire clk,
	input wire rst,
	input wire [2:0]coin5,coin10,
	output reg dispense,
	output reg return_change
);

	parameter IDLE = 3'b000,
				 accept_coin = 3'b001,
				 returning_change = 3'b010,
				 dispensing_water =3'b011,
				 COIN5 = 3'b100,
				 COIN10 = 3'b101;
				 
	reg [2:0] cur_state,next_state;
	
	always @(posedge clk or negedge rst) begin
		if(!rst)
			cur_state <= IDLE;
		else
			cur_state <= next_state;
	end
	
	always @(*) begin
		next_state = cur_state;
		dispense = 1'b0;
		return_change = 1'b0;
		case(cur_state)
			IDLE: begin
				if(coin5)
					next_state = COIN5;
				if(coin10)
					next_state = COIN10;
			end
			
			COIN5: begin
				if(coin5)
					next_state = COIN10;
				if(coin10)
					next_state = dispensing_water;
			end
					
			COIN10: begin
				if(coin5)
					next_state = dispensing_water;
				if(coin10)
					next_state = returning_change;
			end
	
			dispensing_water: begin
				dispense = 1'b1;
				next_state = IDLE;
			end
			
			returning_change: begin
				return_change = 1'b1;
				dispense = 1'b1;
				next_state = IDLE;
			end
			
			default: begin
				next_state = IDLE;
			end
		endcase
	end
endmodule
				
			
				
					