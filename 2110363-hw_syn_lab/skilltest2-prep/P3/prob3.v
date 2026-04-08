module prob3 (
    input  wire clk,
    input  wire reset,
    input  wire inp,
    output wire out
);

`ifdef COCOTB_SIM
    initial begin
        $dumpfile("waveform.vcd");  // Name of the dump file
        $dumpvars(0, prob3);  // Dump all variables for the top module
    end
`endif

    localparam A = 0;
    localparam B = 1;
    localparam C = 2;
    localparam D = 3;
    localparam E = 4;

    reg [2:0] state;
    reg [2:0] next_state;
    reg       out_reg;
    assign out = out_reg;

    // Separate output from state transition because output somehow should be changed asynchronously
    // While state transition must be synchronous
    always @(posedge clk) begin
        if (reset) begin
            state <= A;
        end else begin
            case (state)
                A:       state <= (inp ? B : A);
                B:       state <= (inp ? D : C);
                C:       state <= (inp ? D : A);
                D:       state <= (inp ? D : E);
                E:       state <= (inp ? A : D);
                default: ;
            endcase
        end
    end

    always @(*) begin
        case (state)
            A:       out_reg <= (inp ? 1 : 0);
            B:       out_reg <= (inp ? 1 : 0);
            C:       out_reg <= (inp ? 0 : 0);
            D:       out_reg <= (inp ? 1 : 0);
            E:       out_reg <= (inp ? 0 : 1);
            default: ;
        endcase
    end

endmodule
