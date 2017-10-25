import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class VentanaSimple extends JFrame{
    public VentanaSimple(){
        setBounds(50,50,500,500);
        JLabel l = new JLabel("Escribe tu nombre");
        JTextField nombre = new JTextField("                   ");
        JButton boton = new JButton("saludo");
        JLabel saludo = new JLabel("");
        setLayout(new FlowLayout());
        add(l);
        add(nombre);
        add(boton);
        add(saludo);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        boton.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent ae){
                String name = nombre.getText();
                saludo.setText("Hola " + name);
            }
        });
        setVisible(true);
    }
    public static void main(String[] args){
        VentanaSimple v = new VentanaSimple();
    }
}
