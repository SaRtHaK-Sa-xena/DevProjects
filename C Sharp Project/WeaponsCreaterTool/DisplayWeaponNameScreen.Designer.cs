namespace WeaponsCreaterTool
{
    partial class DisplayWeaponNameScreen
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.CreateWeaponLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.AddWeaponButton = new System.Windows.Forms.Button();
            this.SaveLoadoutButton = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // CreateWeaponLabel
            // 
            this.CreateWeaponLabel.BackColor = System.Drawing.SystemColors.AppWorkspace;
            this.CreateWeaponLabel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.CreateWeaponLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CreateWeaponLabel.Location = new System.Drawing.Point(12, 0);
            this.CreateWeaponLabel.Name = "CreateWeaponLabel";
            this.CreateWeaponLabel.Size = new System.Drawing.Size(614, 58);
            this.CreateWeaponLabel.TabIndex = 0;
            this.CreateWeaponLabel.Text = "Display Weapon";
            // 
            // label1
            // 
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 95);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(387, 35);
            this.label1.TabIndex = 1;
            this.label1.Text = "Weapon Name:";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(203, 95);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(196, 36);
            this.textBox1.TabIndex = 2;
            this.toolTip1.SetToolTip(this.textBox1, "Custom Name");
            // 
            // label2
            // 
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(12, 154);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(387, 35);
            this.label2.TabIndex = 3;
            this.label2.Text = "Attribute:";
            // 
            // label3
            // 
            this.label3.BackColor = System.Drawing.Color.White;
            this.label3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(128, 154);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(271, 37);
            this.label3.TabIndex = 4;
            // 
            // AddWeaponButton
            // 
            this.AddWeaponButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AddWeaponButton.Location = new System.Drawing.Point(406, 95);
            this.AddWeaponButton.Name = "AddWeaponButton";
            this.AddWeaponButton.Size = new System.Drawing.Size(220, 96);
            this.AddWeaponButton.TabIndex = 5;
            this.AddWeaponButton.Text = "Add Weapon";
            this.toolTip1.SetToolTip(this.AddWeaponButton, "Adds Weapon To InGame List");
            this.AddWeaponButton.UseVisualStyleBackColor = true;
            this.AddWeaponButton.Click += new System.EventHandler(this.AddWeaponButton_Click);
            // 
            // SaveLoadoutButton
            // 
            this.SaveLoadoutButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SaveLoadoutButton.Location = new System.Drawing.Point(406, 234);
            this.SaveLoadoutButton.Name = "SaveLoadoutButton";
            this.SaveLoadoutButton.Size = new System.Drawing.Size(220, 96);
            this.SaveLoadoutButton.TabIndex = 6;
            this.SaveLoadoutButton.Text = "Save Loadout";
            this.toolTip1.SetToolTip(this.SaveLoadoutButton, "Saves Entire Loadout");
            this.SaveLoadoutButton.UseVisualStyleBackColor = true;
            // 
            // pictureBox1
            // 
            this.pictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox1.Location = new System.Drawing.Point(17, 216);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(383, 202);
            this.pictureBox1.TabIndex = 7;
            this.pictureBox1.TabStop = false;
            this.toolTip1.SetToolTip(this.pictureBox1, "Selected Image");
            // 
            // DisplayWeaponNameScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.SaveLoadoutButton);
            this.Controls.Add(this.AddWeaponButton);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.CreateWeaponLabel);
            this.Name = "DisplayWeaponNameScreen";
            this.Text = "DisplayWeaponNameScreen";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label CreateWeaponLabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button AddWeaponButton;
        private System.Windows.Forms.Button SaveLoadoutButton;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.ToolTip toolTip1;
    }
}