using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace task10
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void submit_Click(object sender, EventArgs e)
        {
            if(string.IsNullOrEmpty(textBox1.Text))
            {
                MessageBox.Show("Please Enter Name");
            }
            if (textBox2.Text.Length != 10)
            {
                MessageBox.Show("Please Enter a valid Contact number");
            }
            if(!((textBox3.Text).Contains("@")))
            {
                MessageBox.Show("Enter a valid gmail");
            }
            MessageBox.Show("Form submitted successfully");
        }
    }
}
