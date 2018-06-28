import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.TextField;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;

public class Calculator{
  
  private TextField input1;
  private TextField input2;
  private TextField result;
  
  public Calculator(){
    JFrame frame = new JFrame("Calculator");
    
    JPanel overallPanel = new JPanel();
    overallPanel.setLayout(new FlowLayout());
    
    input1 = new TextField(30);
    input2 = new TextField(30);
    result = new TextField(30);
    overallPanel.add(input1);
    JPanel operationsPanel = new JPanel();
    overallPanel.add(operationsPanel);
    
    operationsPanel.setLayout(new GridLayout(2, 2));
    JButton additionButton = new JButton("+");
    additionButton.addActionListener(new OperationListener('+'));
    JButton subtractionButton = new JButton("-");
    subtractionButton.addActionListener(new OperationListener('-'));
    JButton multiplicationButton = new JButton("*");
    multiplicationButton.addActionListener(new OperationListener('*'));
    JButton divisionButton = new JButton("/");
    divisionButton.addActionListener(new OperationListener('/'));
    
    operationsPanel.add(additionButton);
    operationsPanel.add(subtractionButton);
    operationsPanel.add(multiplicationButton);
    operationsPanel.add(divisionButton);
    
    overallPanel.add(input2);
    overallPanel.add(result);
    
    frame.getContentPane().add(overallPanel);
    
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(1000, 400);
    frame.setVisible(true);
  }
  
  public static void main(String[] args){
    Calculator c = new Calculator();
  }
  
  private void performOp(char op){
    if(op == '+'){
      double firstNum = Double.parseDouble(input1.getText());
      double secondNum = Double.parseDouble(input2.getText());
      result.setText(((Double) (firstNum+secondNum)).toString());
    }
    if(op == '-'){
      double firstNum = Double.parseDouble(input1.getText());
      double secondNum = Double.parseDouble(input2.getText());
      result.setText(((Double) (firstNum-secondNum)).toString());
    }
    if(op == '*'){
      double firstNum = Double.parseDouble(input1.getText());
      double secondNum = Double.parseDouble(input2.getText());
      result.setText(((Double) (firstNum*secondNum)).toString());
    }
    if(op == '/'){
      double firstNum = Double.parseDouble(input1.getText());
      double secondNum = Double.parseDouble(input2.getText());
      if(secondNum != 0.0)
        result.setText(((Double) (firstNum/secondNum)).toString());
      else
        result.setText("Error: divide by 0");
    }
  }
  
  private class OperationListener implements ActionListener{
    
    private char op;
    
    public OperationListener(char op){
      this.op = op;
    }
    
    public void actionPerformed(ActionEvent e){
      performOp(op);
    }
  }
  
}
