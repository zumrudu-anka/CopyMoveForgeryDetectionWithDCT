#pragma once
#include <windows.h>
#include "atlstr.h"

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
		Bitmap ^main_image; 
		BYTE *raw_intensity, *quantization_table;
		int width_m_image,height_m_image;
		double *Fuv;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  operationsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  showIntensityToolStripMenuItem;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ToolStripMenuItem^  dCTToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  quantizationToolStripMenuItem;
	private: System::Windows::Forms::ProgressBar^  progressBar1;




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
			this->quantizationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DosyaSecDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
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
					this->dCTToolStripMenuItem, this->quantizationToolStripMenuItem
			});
			this->operationsToolStripMenuItem->Name = L"operationsToolStripMenuItem";
			this->operationsToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			this->operationsToolStripMenuItem->Text = L"Operations";
			// 
			// showIntensityToolStripMenuItem
			// 
			this->showIntensityToolStripMenuItem->Name = L"showIntensityToolStripMenuItem";
			this->showIntensityToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->showIntensityToolStripMenuItem->Text = L"Show Intensity";
			this->showIntensityToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showIntensityToolStripMenuItem_Click);
			// 
			// dCTToolStripMenuItem
			// 
			this->dCTToolStripMenuItem->Name = L"dCTToolStripMenuItem";
			this->dCTToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->dCTToolStripMenuItem->Text = L"DCT";
			this->dCTToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dCTToolStripMenuItem_Click);
			// 
			// quantizationToolStripMenuItem
			// 
			this->quantizationToolStripMenuItem->Name = L"quantizationToolStripMenuItem";
			this->quantizationToolStripMenuItem->Size = System::Drawing::Size(151, 22);
			this->quantizationToolStripMenuItem->Text = L"Quantization";
			this->quantizationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::quantizationToolStripMenuItem_Click);
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
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->numericUpDown1->Location = System::Drawing::Point(631, 384);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(39, 24);
			this->numericUpDown1->TabIndex = 0;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"8 x 8", L"16 x 16" });
			this->comboBox1->Location = System::Drawing::Point(404, 333);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(698, 416);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->numericUpDown1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
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
				byte raw = main_image->GetPixel(j, i).R * 0.299f+main_image->GetPixel(j,i).G*0.587f+main_image->GetPixel(j,i).B*0.114f;
				raw_intensity[i*width_m_image+j]=raw;
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
	
	Fuv = new double[(height_m_image - 7) * (width_m_image - 7) * 64];
	progressBar1->Visible = true;
	progressBar1->Maximum = (height_m_image - 7) * (width_m_image - 7);

	for (int i = 0; i < height_m_image - 7; i++) {
		for (int j = 0; j < width_m_image - 7; j++) {

			for (int u = 0; u < 8; u++) {
				for (int v = 0; v < 8; v++) {
					double cu = u == 0 ? 1 / double(sqrt(2)) : 1;
					double cv = v == 0 ? 1 / double(sqrt(2)) : 1;
					double sum = 0;
					byte countk = 0;
					for (int k = i; k < i + 8; k++) {
						byte countt = 0;
						for (int t = j; t < j + 8; t++) {
							sum += raw_intensity[k * width_m_image + t] * (cos(2 * countk + 1) * u * Math::PI / 16) * (cos(2 * countt + 1) * v * Math::PI / 16);
							countt++;
						}
						countk++;
					}
					Fuv[(i*width_m_image - 7) + (64 * j) + (u * 8) + v] = cu * cv * sum / 4;
				}
			}
			progressBar1->Increment(1);
		}
	}
	progressBar1->Visible = false;

}

private: System::Void quantizationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	quantization_table = new BYTE[64];
	SetQuantizationTable(8, 8);
	for (int i = 0; i < (height_m_image - 7) * (width_m_image - 7); i++) {
		for (int j = 0; j < 64; j++) {
			Fuv[i * 64 + j] /= quantization_table[j];
			int a = int(Fuv[i * 64 + j]);
			Fuv[i * 64 + j] = fabs(Fuv[i * 64 + j] - a) > fabs(a + 1 - Fuv[i * 64 + j]) ? (a + 1) : a;
		}
	}
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

private:void diagonalOrder(double *DCTBlock, byte block_row, byte block_column, byte save_size)
{
	// There will be ROW+COL-1 lines in the output 
	for (int line = 1; line <= (block_row + block_column - 1); line++)
	{
		/* Get column index of the first element in this line of output.
		The index is 0 for first ROW lines and line - ROW for remaining
		lines  */
		int start_col = max(0, line - block_row);

		/* Get count of elements in this line. The count of elements is
		equal to minimum of line number, COL-start_col and ROW */
		int count = min(min(line, (block_column - start_col)), block_row);

		/* Print elements of this line */
		for (int j = 0; j < count; j++)
			printf("%5d ", DCTBlock[(min(block_row, line) - j - 1) * block_column + (start_col + j)]);

		/* Ptint elements of next diagonal on next line */
		printf("\n");
	}
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
