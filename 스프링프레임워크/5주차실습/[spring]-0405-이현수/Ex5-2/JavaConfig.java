package Ex4_2;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Scope;

@Configuration
public class JavaConfig {
	@Bean
	public OperatorBean operatorBean() {
		return new PlusOp(operand(), operand());
	}
	
	@Bean
	@Scope("prototype")
	public Operand operand() {
		return new Operand(30);
	}
}
