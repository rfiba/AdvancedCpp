#pragma once
#include "board.h"
#include <string> 

namespace GameOfLife {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			timer->Interval = 700;
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
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
			 static Timer^ timer;
			 
			 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 45);
			this->pictureBox1->MaximumSize = System::Drawing::Size(921, 473);
			this->pictureBox1->MinimumSize = System::Drawing::Size(921, 473);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(921, 473);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MainWindow::pictureBox1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainWindow::openFileDialog1_FileOk);
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
			this->button4->Location = System::Drawing::Point(336, 13);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Save to file";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainWindow::button4_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(945, 530);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		MouseEventArgs^ me = (MouseEventArgs^)e;
		if(me->Button == System::Windows::Forms::MouseButtons::Right){
			MessageBox::Show("Praw;");
		}
	}

	private: System::Void onTimedEvent(System::Object^  sender, System::EventArgs^  e) {
		mainBoard.nextStep();
		for (int i = 0; i < mainBoard.getSizeM(); i++) {
			for (int j = 0; j < mainBoard.getSizeN(); j++) {
				bool tmp = mainBoard.getState(i, j);

				if (tmp) {

					graphics->FillRectangle(brush, j * 10 + 1, i * 10 + 1, 10 - 1, 10 - 1);
				}
			}
		}
		pictureBox1->Image = image;
	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		mainBoard.createBoardFromFile("board.rle");
		
		MessageBox::Show(mainBoard.getSizeN().ToString());
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		timer->Start();
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	timer->Stop();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	
	mainBoard.createFileFromBoard("board_resul.rle");
}
};
}
