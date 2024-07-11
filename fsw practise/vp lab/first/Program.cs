using System.Windows.Forms;
using System.Drawing;
namespace first{

public class Program : Form
{
    public Program() 
    {
        InitComponents();
    }

    private void InitComponents()
    {
        ColorDialog dlg = new ColorDialog();
        dlg.ShowDialog();
    }
    [STAThread]
    static void Main()
    {
        Application.SetHighDpiMode(HighDpiMode.SystemAware);
        Application.EnableVisualStyles();
        Application.Run(new Program());
    }    
}
}