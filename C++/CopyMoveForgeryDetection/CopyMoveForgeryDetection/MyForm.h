#pragma once
#include <windows.h>
#include "atlstr.h"
#include "Blocks.h"

namespace CopyMoveForgeryDetection {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  DosyaSecDialog;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private:
		/// <summary>
		Bitmap ^main_image, ^resultimage; 
		BYTE *raw_intensity, *quantization_table;
		array<Blocks^>^ myblocks;
		int width_m_image,height_m_image;
		double *Fuv;
		int *DCT_array_with_threshold;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  operationsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showIntensityToolStripMenuItem;
	private: System::Windows::Forms::NumericUpDown^  BetweenBlocktoCompareNumeric;
	private: System::Windows::Forms::ToolStripMenuItem^  dCTToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  DetectForgeryToolStripMenuItem;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
			 ///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->operationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showIntensityToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dCTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DetectForgeryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DosyaSecDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->BetweenBlocktoCompareNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BetweenBlocktoCompareNumeric))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuToolStripMenuItem,
					this->operationsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(698, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->menuToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// operationsToolStripMenuItem
			// 
			this->operationsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->showIntensityToolStripMenuItem,
					this->dCTToolStripMenuItem, this->DetectForgeryToolStripMenuItem
			});
			this->operationsToolStripMenuItem->Name = L"operationsToolStripMenuItem";
			this->operationsToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			this->operationsToolStripMenuItem->Text = L"Operations";
			// 
			// showIntensityToolStripMenuItem
			// 
			this->showIntensityToolStripMenuItem->Name = L"showIntensityToolStripMenuItem";
			this->showIntensityToolStripMenuItem->Size = System::Drawing::Size(188, 22);
			this->showIntensityToolStripMenuItem->Text = L"Show Intensity";
			this->showIntensityToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showIntensityToolStripMenuItem_Click);
			// 
			// dCTToolStripMenuItem
			// 
			this->dCTToolStripMenuItem->Name = L"dCTToolStripMenuItem";
			this->dCTToolStripMenuItem->Size = System::Drawing::Size(188, 22);
			this->dCTToolStripMenuItem->Text = L"DCT";
			this->dCTToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dCTToolStripMenuItem_Click);
			// 
			// DetectForgeryToolStripMenuItem
			// 
			this->DetectForgeryToolStripMenuItem->Name = L"DetectForgeryToolStripMenuItem";
			this->DetectForgeryToolStripMenuItem->Size = System::Drawing::Size(188, 22);
			this->DetectForgeryToolStripMenuItem->Text = L"Try To Detect Forgery";
			this->DetectForgeryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::DetectForgeryToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(320, 240);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(351, 27);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(320, 240);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// BetweenBlocktoCompareNumeric
			// 
			this->BetweenBlocktoCompareNumeric->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->BetweenBlocktoCompareNumeric->Location = System::Drawing::Point(632, 439);
			this->BetweenBlocktoCompareNumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->BetweenBlocktoCompareNumeric->Name = L"BetweenBlocktoCompareNumeric";
			this->BetweenBlocktoCompareNumeric->Size = System::Drawing::Size(39, 25);
			this->BetweenBlocktoCompareNumeric->TabIndex = 0;
			this->BetweenBlocktoCompareNumeric->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->BetweenBlocktoCompareNumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::Color::DarkSlateGray;
			this->progressBar1->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->progressBar1->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->progressBar1->Location = System::Drawing::Point(12, 274);
			this->progressBar1->MarqueeAnimationSpeed = 10;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(658, 32);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 4;
			this->progressBar1->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(262, 442);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(364, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Threshold Value Which Between Blocks to Compare: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(300, 337);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"label2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(698, 475);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BetweenBlocktoCompareNumeric);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->progressBar1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BetweenBlocktoCompareNumeric))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	DosyaSecDialog->InitialDirectory = "..\\Images\\";
	DosyaSecDialog->Filter = "Bitmap Files (*.bmp)|*.bmp|All Files (*.*)|*.*";
	DosyaSecDialog->FilterIndex = 1;
	DosyaSecDialog->RestoreDirectory = true;
	DosyaSecDialog->Title = "Dosya Seçimi";

	if (DosyaSecDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

		main_image = gcnew Bitmap(DosyaSecDialog->FileName);
			
		height_m_image=main_image->Height;
		width_m_image=main_image->Width;
			
		pictureBox1->Width = width_m_image;
		pictureBox1->Height = height_m_image;
		pictureBox1->Image = main_image;
			
		raw_intensity = new BYTE[width_m_image*height_m_image];

		for (int i = 0; i < height_m_image; i++) {
			for (int j = 0; j < width_m_image; j++) {
				raw_intensity[i*width_m_image + j] = main_image->GetPixel(j, i).R * 0.299f + main_image->GetPixel(j, i).G * 0.587f + main_image->GetPixel(j, i).B * 0.114f;
			}
		}

	}
}

private: void ShowOnPictureBox(BYTE *rawarray, int w_of_raw, int h_of_raw) {
		
	Bitmap ^surface=gcnew Bitmap(w_of_raw,h_of_raw);

	for (int i = 0; i < h_of_raw; i++) {
		for (int j = 0; j < w_of_raw; j++) {
			surface->SetPixel(j,i,Color::FromArgb(rawarray[i*w_of_raw+j], rawarray[i*w_of_raw + j], rawarray[i*w_of_raw + j]));
		}
	}

	pictureBox2->Width=w_of_raw;
	pictureBox2->Height=h_of_raw;
	pictureBox2->Image=surface;
}

private: System::Void showIntensityToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	ShowOnPictureBox(raw_intensity, width_m_image, height_m_image);
}

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm::Close();
}
	
private: System::Void dCTToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	//Fuv = new double[(height_m_image - 7) * (width_m_image - 7) * 64];
	//DCT_array_with_threshold = new int[(height_m_image - 7) * (width_m_image - 7) * 16];
	
	myblocks = gcnew array<Blocks^>((height_m_image - 7) * (width_m_image - 7));
	
	quantization_table = new BYTE[64];
	SetQuantizationTable(8, 8);
	
	progressBar1->Visible = true;
	progressBar1->Maximum = (height_m_image - 7) * (width_m_image - 7);
	
	int calculated_dctblock_count = 0;
	
	for (int i = 0; i < height_m_image - 7; i++) {
		for (int j = 0; j < width_m_image - 7; j++) {
			double *Fuv = new double[64];
			for (int u = 0; u < 8; u++) {
				for (int v = 0; v < 8; v++) {
					double cu = u == 0 ? 1 / double(sqrt(2)) : 1;
					double cv = v == 0 ? 1 / double(sqrt(2)) : 1;
					double sum = 0;
					byte countk = 0;
					for (int k = i; k < i + 8; k++) {
						byte countt = 0;
						for (int t = j; t < j + 8; t++) {
							sum += raw_intensity[k * width_m_image + t] * (cos((2 * countk + 1) * u * Math::PI / 16)) * (cos((2 * countt + 1) * v * Math::PI / 16));
							countt++;
						}
						countk++;
					}
					//Hesaplanan Tum DCT blocklarini bellekte tutmak istersek(64 hucreyi de) bu sekilde yapabiliriz...
					//Fuv[(i * (width_m_image - 7) * 64) + (64 * j) + (u * 8) + v] = cu * cv * sum / 4;
					Fuv[u * 8 + v] = cu * cv * sum / 4;
				}
			}
			// Quantized_array, each_block_row, each_block_column, diagonal_saved_size, calculated_dct_block
			myblocks[calculated_dctblock_count] = gcnew Blocks();
			myblocks[calculated_dctblock_count]->SetDiagonalOrder(DiagonalOrder(MakeQuantization(Fuv, 64), 8, 8, 15), i, j);
			
			calculated_dctblock_count++;

			progressBar1->Increment(1);
			delete[] Fuv;
		}
	}
	progressBar1->Visible = false;

}

private: System::Void DetectForgeryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	Bitmap ^resultimage = gcnew Bitmap(width_m_image, height_m_image);
	for (int i = 0; i < height_m_image; i++)
	{
		for (int j = 0; j < width_m_image; j++)
		{
			resultimage->SetPixel(j, i, Color::Black);
		}
	}
	progressBar1->Value = 0;
	progressBar1->Visible = true;
	progressBar1->Maximum = (height_m_image - 7) * (width_m_image - 7);

	int similar_count;

	for (int i1 = 0; i1 < height_m_image - 7 - 6; i1++)
	{
		for (int j1 = 0; j1 < width_m_image - 7 - 6; j1++)
		{
			for (int i2 = i1; i2 < height_m_image - 7 - 6; i2++)
			{
				for (int j2 = j1; j2 < width_m_image - 7 - 6; j2++)
				{
					if (sqrt(pow((i2 - i1), 2) + pow((j2 - j1), 2)) >= int(BetweenBlocktoCompareNumeric->Value))
					{
						double shiftvectordistance = CalcVectorDistanceBetweenBlocks(myblocks[i1 * (width_m_image - 7) + j1], myblocks[i2 * (width_m_image - 7) + j2]);
						similar_count = 0;
						if (shiftvectordistance < 0.5f)
						{
							int *similarblockscoords;
							
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
												if (similar_count == 0) {
													similar_count++;
													similarblockscoords = new int[similar_count * 4];
													similarblockscoords[0] = myblocks[k1 * (width_m_image - 7) + t1]->GetRow();
													similarblockscoords[1] = myblocks[k1 * (width_m_image - 7) + t1]->GetColumn();
													similarblockscoords[2] = myblocks[k2 * (width_m_image - 7) + t2]->GetRow();
													similarblockscoords[3] = myblocks[k2 * (width_m_image - 7) + t2]->GetColumn();
												}
												else {
													int *temp = new int[similar_count * 4];
													for (int i = 0; i < similar_count * 4; i++) {
														temp[i] = similarblockscoords[i];
													}
													similar_count++;
													similarblockscoords = new int[similar_count * 4];
													for (int i = 0; i < (similar_count - 1) * 4; i++) {
														similarblockscoords[i] = temp[i];
													}
													delete[] temp;
													similarblockscoords[(similar_count - 1) * 4] = myblocks[k1 * (width_m_image - 7) + t1]->GetRow();
													similarblockscoords[(similar_count - 1) * 4 + 1] = myblocks[k1 * (width_m_image - 7) + t1]->GetColumn();
													similarblockscoords[(similar_count - 1) * 4 + 2] = myblocks[k2 * (width_m_image - 7) + t2]->GetRow();
													similarblockscoords[(similar_count - 1) * 4 + 3] = myblocks[k2 * (width_m_image - 7) + t2]->GetColumn();
												}
												
												
											}
											t1++;
										}
										k1++;
									}
								}
							}
							
							if (similar_count > 15)
							{
								for (int k = 0; k < similar_count; k += 2)
								{
									resultimage->SetPixel(similarblockscoords[k + 1], similarblockscoords[k], Color::White);
								}
							}
						}
					}
				}
			}
			progressBar1->Increment(1);
		}
	}

	progressBar1->Visible = false;

	pictureBox2->Image = resultimage;
	
}

private: void SetQuantizationTable(byte size, byte mainsize) {
	for (byte i = 0; i < size; i++) {
		for (byte j = 0; j < size; j++) {
			quantization_table[i*mainsize + j] = pow(2, size - 2);
		}
	}
	if (size != 2) {
		SetQuantizationTable(size - 1, mainsize);
	}
}

private:int *DiagonalOrder(int *quantized_block, byte block_row, byte block_column, byte save_size)
{
	// There will be ROW+COL-1 lines in the output
	byte saving_cell_count = 0;
	int *diagonaled_block = new int[save_size];
	for (int line = 1; line < block_row + block_column ; line++)
	{
		/* Get column index of the first element in this line of output.
		The index is 0 for first ROW lines and line - ROW for remaining
		lines  */

		int start_col = max(0, line - block_row);

		/* Get count of elements in this line. The count of elements is
		equal to minimum of line number, COL-start_col and ROW */
		int count = min(min(line, (block_column - start_col)), block_row);

		/* Print elements of this line */
		for (int j = 0; j < count; j++) {
			diagonaled_block[saving_cell_count] = quantized_block[(min(block_row, line) - j - 1) * block_column + (start_col + j)];
			saving_cell_count++;
		}
		if (saving_cell_count == save_size) {
			return diagonaled_block;
		}
	}
}

private: int *MakeQuantization(double *Fuv,int size_of_dctblock) {
	
	int *quanta_array = new int[size_of_dctblock];
	for (int i = 0; i < size_of_dctblock; i++)
	{
		Fuv[i] /= quantization_table[i];
		int a = int(Fuv[i]);
		quanta_array[i] = fabs(Fuv[i] - a) > fabs(a + 1 - Fuv[i]) ? (a + 1) : a;
	}
	return quanta_array;
}

private: double CalcVectorDistanceBetweenBlocks(Blocks ^block1, Blocks ^block2)
{
	int *b1 = block1->GetDiagonalOrder();
	int *b2 = block2->GetDiagonalOrder();

	double shiftvectordistance = 0;
	for (int i = 0; i < 15; i++)
	{
		shiftvectordistance += pow((b1[i] - b2[i]), 2);
	}
	shiftvectordistance = sqrt(shiftvectordistance);
	return shiftvectordistance;
}

private: void CalculateCbaCra() {
	BYTE *cba = new BYTE[width_m_image*height_m_image / 4];
	BYTE *cra = new BYTE[width_m_image*height_m_image / 4];
	int index = 0;

	for (int i = 0; i < height_m_image; i += 2) {
		for (int j = 0; j < width_m_image; j += 2) {
			BYTE cb = 0, cr = 0;
			for (int k = i; k < i + 2; k++) {
				for (int t = j; t < j + 2; t++) {
					cb += 0.564f * (main_image->GetPixel(t, k).B - raw_intensity[k*width_m_image + t]);
					cr += 0.713f * (main_image->GetPixel(t, k).R - raw_intensity[k*width_m_image + t]);
				}
			}
			cb /= 4;
			cr /= 4;
			cba[index] = cb;
			cra[index] = cr;
			index++;
		}
	}
}

};
}

















/*
byte right_count=1,down_count=1,cross_count=1;
//Saga dogru benzerlikler
do
{
	shift_vector_distance2 = 0;
	for (int k = 0; k < 16; k++) {
		shift_vector_distance2 += pow((DCT_array_with_threshold[i + (right_count * 16) + k] - DCT_array_with_threshold[j + (16 * right_count) + k]), 2);
	}
	shift_vector_distance2 = sqrt(shift_vector_distance2);
	if (shift_vector_distance2 < 1) {
		right_count++;
	}
	else {
		similar_right = false;
	}
} while (similar_right);
//Asagi dogru benzerlikler
do
{
	shift_vector_distance2 = 0;
	for (int k = 0; k < 16; k++) {
		shift_vector_distance2 += pow((DCT_array_with_threshold[i + (down_count * (width_m_image - 7) * 16) + k] - DCT_array_with_threshold[j + (down_count * (width_m_image - 7) * 16) + k]), 2);
	}
	shift_vector_distance2 = sqrt(shift_vector_distance2);
	if (shift_vector_distance2 < 1) {
		down_count++;
	}
	else {
		similar_down = false;
	}
} while (similar_down);
//Carpraz benzerlikler
do
{
	shift_vector_distance2 = 0;
	for (int k = 0; k < 16; k++) {
		shift_vector_distance2 += pow((DCT_array_with_threshold[i + (cross_count * (width_m_image - 7) * 16) + (cross_count * 16) + k] - DCT_array_with_threshold[j + (cross_count * (width_m_image - 7) * 16) + (cross_count * 16) + k]), 2);
	}
	shift_vector_distance2 = sqrt(shift_vector_distance2);
	if (shift_vector_distance2 < 1) {
		cross_count++;
	}
	else {
		similar_cross = false;
	}
} while (similar_cross);

countofsimilarity = cross_count + right_count + down_count;

*/




/*while (shift_vector_distance2 < 1) {
	shift_vector_distance2 = 0;
	for (int k = 0; k < 16; k++) {
		shift_vector_distance2 += pow((DCT_array_with_threshold[i + (right_count * 16) + k] - DCT_array_with_threshold[j + (16 * right_count) + k]), 2);
	}
	shift_vector_distance2 = sqrt(shift_vector_distance2);
	right_count++;
}
shift_vector_distance2 = 0;
while (shift_vector_distance2 < 1) {
	shift_vector_distance2 = 0;
	for (int k = 0; k < 16; k++) {
		shift_vector_distance2 += pow((DCT_array_with_threshold[i + (down_count * (width_m_image - 7) * 16) + k] - DCT_array_with_threshold[j + (down_count * (width_m_image - 7) * 16) + k]), 2);
	}
	shift_vector_distance2 = sqrt(shift_vector_distance2);
	down_count++;
}
while (shift_vector_distance2 < 1) {
	shift_vector_distance2 = 0;
	for (int k = 0; k < 16; k++) {
		shift_vector_distance2 += pow((DCT_array_with_threshold[i + (cross_count * (width_m_image - 7) * 16) + (cross_count * 16) + k] - DCT_array_with_threshold[j + (cross_count * (width_m_image - 7) * 16) + (cross_count * 16) + k]), 2);
	}
	shift_vector_distance2 = sqrt(shift_vector_distance2);
	cross_count++;
}
if ((right_count + cross_count + down_count) > 15) {

}*/
