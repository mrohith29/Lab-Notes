using System.Windows.Forms;
using System.Drawing;
namespace task9n;
public class Program : Form
{
        public Program() {
            InitComponents();
        }
        private void InitComponents() {
            ColorDialog dlg = new ColorDialog();
            dlg.ShowDialog();
        }
    
    /// <summary>
    ///  The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main()
    {
        // To customize application configuration such as set high DPI settings or default font,
        // see https://aka.ms/applicationconfiguration.
        ApplicationConfiguration.Initialize();
        Application.SetHighDpiMode(HighDpiMode.SystemAware);
        Application.EnableVisualStyles();
        Application.Run(new Program());
    }    
}