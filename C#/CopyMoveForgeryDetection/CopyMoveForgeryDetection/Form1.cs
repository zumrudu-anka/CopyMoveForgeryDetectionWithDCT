using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Math;

namespace CopyMoveForgeryDetection
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        Bitmap main_image;
        Blocks[] myblocks;
        byte[] raw_intensity;
        byte[] quantization_table;
        int height_m_image, width_m_image;

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DosyaSecDialog.InitialDirectory = "..\\Images\\";
            DosyaSecDialog.Filter = "Bitmap Files (*.bmp)|*.bmp|All Files (*.*)|*.*";
            DosyaSecDialog.FilterIndex = 1;
            DosyaSecDialog.RestoreDirectory = true;
            DosyaSecDialog.Title = "Dosya Seçimi";

            if (DosyaSecDialog.ShowDialog() == DialogResult.OK)
            {

                main_image = new Bitmap(DosyaSecDialog.FileName);

                height_m_image = main_image.Height;
                width_m_image = main_image.Width;

                pictureBox1.Width = width_m_image;
                pictureBox1.Height = height_m_image;
                pictureBox1.Image = main_image;

                raw_intensity = new byte[width_m_image * height_m_image];

                for (int i = 0; i < height_m_image; i++)
                {
                    for (int j = 0; j < width_m_image; j++)
                    {
                        raw_intensity[i * width_m_image + j] = Convert.ToByte(main_image.GetPixel(j, i).R * 0.299f + main_image.GetPixel(j, i).G * 0.587f + main_image.GetPixel(j, i).B * 0.114f);
                    }
                }
            }
        }
        
        private void dCTToolStripMenuItem_Click(object sender, EventArgs e)
        {
            myblocks = new Blocks[(height_m_image - 7) * (width_m_image - 7)];

            quantization_table = new byte[64];
            SetQuantizationTable(8, 8);

            progressBar1.Visible = true;
            progressBar1.Maximum = (height_m_image - 7) * (width_m_image - 7);

            int calculated_dctblock_count = 0;

            for (int i = 0; i < height_m_image - 7; i++)
            {
                for (int j = 0; j < width_m_image - 7; j++)
                {
                    double[] Fuv = new double[64];
                    for (int u = 0; u < 8; u++)
                    {
                        for (int v = 0; v < 8; v++)
                        {

                            double cu = u == 0 ? 1 / Convert.ToDouble(Sqrt(2)) : 1;
                            double cv = v == 0 ? 1 / Convert.ToDouble(Sqrt(2)) : 1;
                            double sum = 0;
                            byte countk = 0;
                            for (int k = i; k < i + 8; k++)
                            {
                                byte countt = 0;
                                for (int t = j; t < j + 8; t++)
                                {
                                    sum += raw_intensity[k * width_m_image + t] * (Cos((2 * countk + 1) * u * PI / 16)) * (Cos((2 * countt + 1) * v * PI / 16));
                                    countt++;
                                }
                                countk++;
                            }
                            //Hesaplanan Tum DCT blocklarini bellekte tutmak istersek(64 hucreyi de) bu sekilde yapabiliriz...
                            //Fuv[(i * (width_m_image - 7) * 64) + (64 * j) + (u * 8) + v] = cu * cv * sum / 4;
                            Fuv[u * 8 + v] = cu * cv * sum / 4;
                        }
                    }
                    myblocks[calculated_dctblock_count] = new Blocks();
                    // Quantized_array, each_block_row, each_block_column, diagonal_saved_size, calculated_dct_block
                    myblocks[calculated_dctblock_count].SetDiagonalOrder(DiagonalOrder(MakeQuantization(Fuv, 64), 8, 8, 15), i, j);


                    calculated_dctblock_count++;

                    progressBar1.Increment(1);
                }
            }

            progressBar1.Visible = false;
        }

        private void tryToDetectForgeryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Bitmap resultimage = new Bitmap(width_m_image, height_m_image);
            for (int i = 0; i < height_m_image; i++)
            {
                for (int j = 0; j < width_m_image; j++)
                {
                    resultimage.SetPixel(j, i, Color.Black);
                }
            }
            progressBar1.Value = 0;
            progressBar1.Visible = true;
            progressBar1.Maximum = (height_m_image - 7) * (width_m_image - 7);

            for (int i1 = 0; i1 < height_m_image - 7 - 6; i1++)
            {
                for (int j1 = 0; j1 < width_m_image - 7 - 6; j1++)
                {
                    for (int i2 = i1; i2 < height_m_image - 7 - 6; i2++)
                    {
                        for (int j2 = j1; j2 < width_m_image - 7 - 6; j2++)
                        {
                            if (Sqrt(Pow((i2 - i1), 2) + Pow((j2 - j1), 2)) >= Convert.ToInt32(Th_Value_Between_Blocks_Numeric.Value))
                            {
                                double shiftvectordistance = CalcVectorDistanceBetweenBlocks(myblocks[i1 * (width_m_image - 7) + j1], myblocks[i2 * (width_m_image - 7) + j2]);
                                if (shiftvectordistance < 0.5f)
                                {
                                    List<int> similarblockscoords = new List<int>();

                                    double shiftvectordistance2;
                                    for (int k1 = i1; k1 < i1 + 5; k1++)
                                    {
                                        for (int t1 = j1; t1 < j1 + 5; t1++)
                                        {
                                            for (int k2 = i2; k2 < i2 + 5; k2++)
                                            {
                                                t1 = j1;
                                                for (int t2 = j2; t2 < j2 + 5; t2++)
                                                {
                                                    shiftvectordistance2 = CalcVectorDistanceBetweenBlocks(myblocks[k1 * (width_m_image - 7) + t1], myblocks[k2 * (width_m_image - 7) + t2]);
                                                    if (shiftvectordistance2 < 0.5f)
                                                    {
                                                        similarblockscoords.Add(myblocks[k1 * (width_m_image - 7) + t1].GetRow());
                                                        similarblockscoords.Add(myblocks[k1 * (width_m_image - 7) + t1].GetColumn());
                                                        similarblockscoords.Add(myblocks[k2 * (width_m_image - 7) + t2].GetRow());
                                                        similarblockscoords.Add(myblocks[k2 * (width_m_image - 7) + t2].GetColumn());
                                                    }
                                                    t1++;
                                                }
                                                k1++;
                                            }
                                        }
                                    }

                                    if (similarblockscoords.Count > 15)
                                    {
                                        for (int k = 0; k < similarblockscoords.Count; k += 2)
                                        {
                                            resultimage.SetPixel(similarblockscoords[k + 1], similarblockscoords[k], Color.White);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    progressBar1.Increment(1);
                }
            }

            progressBar1.Visible = false;

            pictureBox2.Image = resultimage;
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void showIntensityToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ShowOnPictureBox(raw_intensity, width_m_image, height_m_image);
        }

        private void ShowOnPictureBox(byte[] rawarray, int w_of_raw, int h_of_raw)
        {
            Bitmap surface = new Bitmap(w_of_raw, h_of_raw);

            for (int i = 0; i < h_of_raw; i++)
            {
                for (int j = 0; j < w_of_raw; j++)
                {
                    surface.SetPixel(j, i, Color.FromArgb(rawarray[i * w_of_raw + j], rawarray[i * w_of_raw + j], rawarray[i * w_of_raw + j]));
                }
            }
            pictureBox2.Width = w_of_raw;
            pictureBox2.Height = h_of_raw;
            pictureBox2.Image = surface;
        }

        private void SetQuantizationTable(byte size, byte mainsize)
        {
            for (byte i = 0; i < size; i++)
            {
                for (byte j = 0; j < size; j++)
                {
                    quantization_table[i * mainsize + j] = Convert.ToByte(Math.Pow(2, size - 2));
                }
            }
            if (size != 2)
            {
                SetQuantizationTable(Convert.ToByte(size - 1), mainsize);
            }
        }

        private int[] MakeQuantization(double[] Fuv, int size_of_dctblock)
        {
            int[] quanta_array = new int[size_of_dctblock];
            for (int i = 0; i < size_of_dctblock; i++)
            {
                Fuv[i] /= quantization_table[i];
                int a = Convert.ToInt32(Fuv[i]);
                quanta_array[i] = Abs(Fuv[i] - a) > Abs(a + 1 - Fuv[i]) ? (a + 1) : a;
            }
            return quanta_array;
        }

        private int[] DiagonalOrder(int[] quantized_block, byte block_row, byte block_column, byte save_size)
        {
            byte saving_cell_count = 0;
            int[] diagonaled_block = new int[save_size];
            for (int line = 1; line < block_row + block_column; line++)
            {
                /* Get column index of the first element in this line of output.
                The index is 0 for first ROW lines and line - ROW for remaining
                lines  */

                int start_col = Max(0, line - block_row);

                /* Get count of elements in this line. The count of elements is
                equal to minimum of line number, COL-start_col and ROW */
                int count = Min(Min(line, (block_column - start_col)), block_row);

                /* Print elements of this line */
                for (int j = 0; j < count; j++)
                {
                    diagonaled_block[saving_cell_count] = quantized_block[(Min(block_row, line) - j - 1) * block_column + (start_col + j)];
                    saving_cell_count++;
                }
                if (saving_cell_count == save_size)
                {
                    return diagonaled_block;
                }
            }
            return diagonaled_block;
        }

        private double CalcVectorDistanceBetweenBlocks(Blocks block1, Blocks block2)
        {
            int[] b1 = new int[15];
            b1 = block1.GetDiagonalOrder();
            int[] b2 = new int[15];
            b2 = block2.GetDiagonalOrder();

            double shiftvectordistance = 0;
            for (int i = 0; i < 15; i++)
            {
                shiftvectordistance += Pow((b1[i] - b2[i]), 2);
            }
            shiftvectordistance = Sqrt(shiftvectordistance);
            return shiftvectordistance;
        }
    }
}
