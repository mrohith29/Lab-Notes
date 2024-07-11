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

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if((string.IsNullOrEmpty(textBox1.Text)))
            {
                MessageBox.Show("Please enter Name");
            }
            if ((string.IsNullOrEmpty(textBox2.Text)))
            {
                MessageBox.Show("Please enter email id");
            }
            if(!(textBox2.Text).Contains("@"))
            {
                MessageBox.Show("Enter valid email");
            }
            if((string.IsNullOrEmpty(textBox3.Text)))
            {
                MessageBox.Show("Enter tje 10digit mobile number");
            }
            if((textBox3.Text).Length != 10)
            {
                MessageBox.Show("Please enter 10 digit mobile numeber");
            }
            MessageBox.Show("Form submitted successfully");
        }
    }
}
