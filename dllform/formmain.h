#include <Windows.h>

#pragma once

namespace dllform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// formmain 的摘要
	/// </summary>
	public ref class formmain : public System::Windows::Forms::Form
	{
	public:
		formmain(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~formmain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  blood_ckb;
	private: System::Windows::Forms::CheckBox^  non_fallen_ckb;
	private: System::Windows::Forms::Timer^  timer_blood;
	private: System::Windows::Forms::Timer^  timer_fallen;
	private: System::Windows::Forms::Timer^  timer_cursorpos;
	private: System::Windows::Forms::Label^  label_x;
	private: System::Windows::Forms::Label^  label_y;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  cursor_ckb;
	private: System::Windows::Forms::Label^  level;
	private: System::Windows::Forms::Label^  label_level;




	private: System::ComponentModel::IContainer^  components;
	protected: 


	protected: 


	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->blood_ckb = (gcnew System::Windows::Forms::CheckBox());
			this->non_fallen_ckb = (gcnew System::Windows::Forms::CheckBox());
			this->timer_blood = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer_fallen = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer_cursorpos = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_x = (gcnew System::Windows::Forms::Label());
			this->label_y = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cursor_ckb = (gcnew System::Windows::Forms::CheckBox());
			this->level = (gcnew System::Windows::Forms::Label());
			this->label_level = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// blood_ckb
			// 
			this->blood_ckb->AutoSize = true;
			this->blood_ckb->Location = System::Drawing::Point(12, 12);
			this->blood_ckb->Name = L"blood_ckb";
			this->blood_ckb->Size = System::Drawing::Size(71, 16);
			this->blood_ckb->TabIndex = 0;
			this->blood_ckb->Text = L"Invincible";
			this->blood_ckb->UseVisualStyleBackColor = true;
			this->blood_ckb->CheckedChanged += gcnew System::EventHandler(this, &formmain::blood_ckb_CheckedChanged);
			// 
			// non_fallen_ckb
			// 
			this->non_fallen_ckb->AutoSize = true;
			this->non_fallen_ckb->Location = System::Drawing::Point(12, 43);
			this->non_fallen_ckb->Name = L"non_fallen_ckb";
			this->non_fallen_ckb->Size = System::Drawing::Size(73, 16);
			this->non_fallen_ckb->TabIndex = 1;
			this->non_fallen_ckb->Text = L"Non fallen";
			this->non_fallen_ckb->UseVisualStyleBackColor = true;
			this->non_fallen_ckb->CheckedChanged += gcnew System::EventHandler(this, &formmain::non_fallen_ckb_CheckedChanged);
			// 
			// timer_blood
			// 
			this->timer_blood->Interval = 10;
			this->timer_blood->Tick += gcnew System::EventHandler(this, &formmain::timer_blood_Tick);
			// 
			// timer_fallen
			// 
			this->timer_fallen->Interval = 10;
			this->timer_fallen->Tick += gcnew System::EventHandler(this, &formmain::timer_fallen_Tick);
			// 
			// timer_cursorpos
			// 
			this->timer_cursorpos->Interval = 10;
			this->timer_cursorpos->Tick += gcnew System::EventHandler(this, &formmain::timer_cursorpos_Tick);
			// 
			// label_x
			// 
			this->label_x->Location = System::Drawing::Point(179, 13);
			this->label_x->Name = L"label_x";
			this->label_x->Size = System::Drawing::Size(70, 23);
			this->label_x->TabIndex = 2;
			this->label_x->Text = L"non";
			// 
			// label_y
			// 
			this->label_y->Location = System::Drawing::Point(179, 44);
			this->label_y->Name = L"label_y";
			this->label_y->Size = System::Drawing::Size(70, 23);
			this->label_y->TabIndex = 3;
			this->label_y->Text = L"non";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(141, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 23);
			this->label1->TabIndex = 4;
			this->label1->Text = L"x:";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(141, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 23);
			this->label2->TabIndex = 5;
			this->label2->Text = L"y:";
			// 
			// cursor_ckb
			// 
			this->cursor_ckb->AutoSize = true;
			this->cursor_ckb->Location = System::Drawing::Point(12, 74);
			this->cursor_ckb->Name = L"cursor_ckb";
			this->cursor_ckb->Size = System::Drawing::Size(85, 16);
			this->cursor_ckb->TabIndex = 6;
			this->cursor_ckb->Text = L"Cursor move";
			this->cursor_ckb->UseVisualStyleBackColor = true;
			// 
			// level
			// 
			this->level->Location = System::Drawing::Point(127, 74);
			this->level->Name = L"level";
			this->level->Size = System::Drawing::Size(32, 23);
			this->level->TabIndex = 5;
			this->level->Text = L"level:";
			// 
			// label_level
			// 
			this->label_level->Location = System::Drawing::Point(179, 74);
			this->label_level->Name = L"label_level";
			this->label_level->Size = System::Drawing::Size(70, 23);
			this->label_level->TabIndex = 3;
			this->label_level->Text = L"non";
			// 
			// formmain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(261, 137);
			this->Controls->Add(this->cursor_ckb);
			this->Controls->Add(this->level);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label_level);
			this->Controls->Add(this->label_y);
			this->Controls->Add(this->label_x);
			this->Controls->Add(this->non_fallen_ckb);
			this->Controls->Add(this->blood_ckb);
			this->MaximizeBox = false;
			this->Name = L"formmain";
			this->Text = L"NS-SHAFT-hack";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &formmain::formmain_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void blood_ckb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void formmain_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer_blood_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void timer_fallen_Tick(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void non_fallen_ckb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) ;
	private: System::Void timer_cursorpos_Tick(System::Object^  sender, System::EventArgs^  e);
	//private: System::Void cursor_ckb_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	
};
}
