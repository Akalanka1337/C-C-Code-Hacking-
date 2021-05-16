using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DayCalculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int day = int.Parse(textBox1.Text);
            int month = int.Parse(textBox2.Text);

            string year1 = textBox3.Text.Substring(0, 1) + textBox3.Text.Substring(1 ,1);
            string year2 = textBox3.Text.Substring(2, 1) +textBox3.Text.Substring(3, 1);

            int year_front = int.Parse(year1);
            int year_back = int.Parse(year2);

            calculate(day, month, year_front, year_back);

        }



        private void calculate(int day, int month, int year_1, int year_2)
        {
            Dictionary<int, string> Days = new Dictionary<int,string>();

            // Days from Sunday to Saturday
            Days.Add(0, "Sunday");
            Days.Add(1, "Monday");
            Days.Add(2, "Tuesday");
            Days.Add(3, "Wednesday");
            Days.Add(4, "Thursday");
            Days.Add(5, "Friday");
            Days.Add(6, "Saturday");


            int NT = day % 7;

            int[] monthz = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
            int MZ = monthz[month-1];

            int JZ2 = (year_2 + (year_2 / 4)) % 7;
            int JHZ = (3 - (year_1 % 4)) * 2;

            int SJ = 0;

            if (checkBox1.Checked && month <= 2)
            {
                SJ = 6;
            }
          

            int WD = (NT + MZ + JHZ + JZ2 + SJ) % 7;

            label1.Text = "It was an: " + Days[WD];


        }
    }
}
