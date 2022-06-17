package Ex4_2;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.ImportResource;
import org.springframework.context.annotation.Scope;

@Configuration
@ComponentScan(basePackages= {"Ex4_2"})
public class JavaConfig {
	@Bean
	public OperatorBean operatorBean() {
		OperatorBean plusop = new PlusOp();
		//plusop.setOperand1(operand());  
		//plusop.setOperand2(operand());
		return plusop;
	}
}
