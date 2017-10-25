import java.util.Scanner;

public class Prueba1{

    protected int edad;
    protected String nombre;
    public Prueba1(int edad, String nombre){
        this.edad = edad;
        this.nombre = nombre;
    }
    public int getEdad(){
        return edad;
    }
    public String getNombre(){
        return nombre;
    }
    protected void printName(){
        System.out.println("mi nombre es: " + nombre);
    }
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.println("Escribe tu nombre");
        String nombre = s.nextLine();
        System.out.println("Escribe tu edad");
        int edad = s.nextInt();
        Prueba1 ejemplo = new Prueba1(edad, nombre);
        ejemplo.printName();
        System.out.println();
        System.out.println("mi edad es: ");
        System.out.println(ejemplo.getEdad());
    }
}
