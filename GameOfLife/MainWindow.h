#pragma once
#include "board.h"
#include <string> 
#include<windows.h>
#include <chrono>

namespace GameOfLife {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace std::chrono;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	board mainBoard;
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			timer = gcnew Timer();
			timer->Tick += gcnew System::EventHandler(this, &MainWindow::onTimedEvent);
			timer->Interval = 1000/fps;
			//timer->Start();
			this->brush = gcnew SolidBrush(System::Drawing::Color::Blue);
			this->image = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			this->graphics = Graphics::FromImage(image);
			pictureBox1->Image = image;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		SolidBrush^ brush;
		Graphics^ graphics;
		Bitmap^ image;
		System::ComponentModel::Container ^components;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;


	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
			 static Timer^ timer;
	private: System::Windows::Forms::Button^  button6;
			 bool manualMode = false;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::Button^  button7;
			 int fps = 30;
			 int interval = 1000/fps;
			 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 81);
			this->pictureBox1->MaximumSize = System::Drawing::Size(921, 473);
			this->pictureBox1->MinimumSize = System::Drawing::Size(921, 473);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(921, 473);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainWindow::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"RLE file";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainWindow::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(139, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainWindow::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(238, 13);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"stop";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainWindow::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(336, 13);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Save to file";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainWindow::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(455, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Available memory (MB)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(575, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(10, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"-";
			// 
			// listBox1
			// 
			this->listBox1->Enabled = false;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Gun", L"Glider", L"Copperhead" });
			this->listBox1->Location = System::Drawing::Point(35, 43);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(93, 30);
			this->listBox1->TabIndex = 7;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(139, 43);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 8;
			this->button5->Text = L"manual";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainWindow::button5_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Enabled = false;
			this->numericUpDown1->Location = System::Drawing::Point(238, 45);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 9;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Enabled = false;
			this->numericUpDown2->Location = System::Drawing::Point(364, 45);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 10;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(490, 42);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 11;
			this->button6->Text = L"set";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainWindow::button6_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(629, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Max FPS";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(685, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(10, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"-";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(629, 47);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"FPS";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Enabled = false;
			this->numericUpDown3->Location = System::Drawing::Point(697, 43);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 20);
			this->numericUpDown3->TabIndex = 15;
			this->numericUpDown3->Maximum = fps;
			this->numericUpDown3->Minimum = 1;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(832, 42);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 16;
			this->button7->Text = L"set FPS";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MainWindow::button7_Click);
			this->button7->Enabled = false;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 578);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MainWindow";
			this->Text = L"Game of life";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		MouseEventArgs^ me = (MouseEventArgs^)e;
		if (manualMode) {
			if (me->Button == System::Windows::Forms::MouseButtons::Right) {
				if (me->X >= mainBoard.getSizeN() * 10 || me->Y >= mainBoard.getSizeN() * 10)
					return;
				//MessageBox::Show("Praw");
				mainBoard.killBasedOnCordinates((int)me->X, (int)me->Y, 10);
			}
			else if (me->Button == System::Windows::Forms::MouseButtons::Left) {
				if (me->X >= mainBoard.getSizeN() * 10 || me->Y >= mainBoard.getSizeN() * 10)
					return;
				//MessageBox::Show("Lew");
				mainBoard.birthBasedOnCordinates((int)me->X, (int)me->Y, 10);
			}
			graphics->Clear(System::Drawing::Color::White);
			for (int i = 0; i < mainBoard.getSizeM(); i++) {
				for (int j = 0; j < mainBoard.getSizeN(); j++) {
					bool tmp = mainBoard.getState(i, j);
					if (tmp)
						graphics->FillRectangle(brush, j * 10 + 1, i * 10 + 1, 10 - 1, 10 - 1);
				}
			}
			pictureBox1->Image = image;
		}
	}

	private: System::Void onTimedEvent(System::Object^  sender, System::EventArgs^  e) {
		auto begin = system_clock::now();
		
		mainBoard.nextStep();
		graphics->Clear(System::Drawing::Color::White);
		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof(statex);
		GlobalMemoryStatusEx(&statex);
		label2->Text = (statex.ullAvailPhys / (1024 * 1024)).ToString();
		for (int i = 0; i < mainBoard.getSizeM(); i++) {
			for (int j = 0; j < mainBoard.getSizeN(); j++) {
				bool tmp = mainBoard.getState(i, j);
				if (tmp)
					graphics->FillRectangle(brush, j * 10 + 1, i * 10 + 1, 10 - 1, 10 - 1);
			}
		}
		pictureBox1->Image = image;
		system_clock::time_point end = system_clock::now();
		auto tmp = duration_cast<milliseconds>(end - begin).count();
		interval = 1000 / tmp;
		label4->Text = interval.ToString();
		this->numericUpDown3->Maximum = interval;
	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->listBox1->Enabled = true;
		graphics->Clear(System::Drawing::Color::White);
		if (this->listBox1->SelectedItem != nullptr) {
			if (this->listBox1->SelectedItem->ToString() == "Gun")
				mainBoard.createBoardFromFile("gun.rle");
			else if (this->listBox1->SelectedItem->ToString() == "Glider")
				mainBoard.createBoardFromFile("glider.rle");
			else if (this->listBox1->SelectedItem->ToString() == "Copperhead")
				mainBoard.createBoardFromFile("copperhead.rle");
		}
		else
			return;
		for (int i = 0; i < mainBoard.getSizeM(); i++) {
			for (int j = 0; j < mainBoard.getSizeN(); j++) {
				bool tmp = mainBoard.getState(i, j);
				if (tmp)
					graphics->FillRectangle(brush, j * 10 + 1, i * 10 + 1, 10 - 1, 10 - 1);
			}
		}
		pictureBox1->Image = image;
		this->button2->Enabled = true;
		
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->button3->Enabled = true;
		this->button2->Enabled = false;
		this->button4->Enabled = false;
		this->button7->Enabled = false;
		this->numericUpDown3->Enabled = false;
		timer->Start();
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	timer->Stop();
	this->button3->Enabled = false;
	this->button2->Enabled = true;
	this->button4->Enabled = true;
	this->button7->Enabled = true;
	this->numericUpDown3->Enabled = true;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	mainBoard.createFileFromBoard("board_result.rle");
	
}

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		
		this->button5->Enabled = false;
		this->numericUpDown1->Enabled = true;
		this->numericUpDown2->Enabled = true;
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	mainBoard.setSizeMAndN((int)this->numericUpDown1->Value, (int)this->numericUpDown2->Value);
	/*MessageBox::Show(mainBoard.getSizeM().ToString());
	MessageBox::Show(mainBoard.getSizeN().ToString());*/
	manualMode = true;
	this->button6->Enabled = false;
	this->button2->Enabled = true;
	this->numericUpDown1->Enabled = false;
	this->numericUpDown2->Enabled = false;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	fps = (int)this->numericUpDown3->Value;
	interval = 1000 / fps;
	timer->Interval = interval;
	
}
};
}
