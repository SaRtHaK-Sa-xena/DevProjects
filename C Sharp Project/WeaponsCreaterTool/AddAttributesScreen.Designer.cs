namespace WeaponsCreaterTool
{
    partial class AddAttributesScreen
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
            this.Attack10Button = new System.Windows.Forms.RadioButton();
            this.Attack20Button = new System.Windows.Forms.RadioButton();
            this.Attack30Button = new System.Windows.Forms.RadioButton();
            this.AddAttributesButton = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // Attack10Button
            // 
            this.Attack10Button.AutoSize = true;
            this.Attack10Button.Location = new System.Drawing.Point(2, 2);
            this.Attack10Button.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Attack10Button.Name = "Attack10Button";
            this.Attack10Button.Size = new System.Drawing.Size(80, 17);
            this.Attack10Button.TabIndex = 0;
            this.Attack10Button.TabStop = true;
            this.Attack10Button.Text = "Attack = 10";
            this.Attack10Button.UseVisualStyleBackColor = true;
            // 
            // Attack20Button
            // 
            this.Attack20Button.AutoSize = true;
            this.Attack20Button.Location = new System.Drawing.Point(2, 39);
            this.Attack20Button.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Attack20Button.Name = "Attack20Button";
            this.Attack20Button.Size = new System.Drawing.Size(80, 17);
            this.Attack20Button.TabIndex = 1;
            this.Attack20Button.TabStop = true;
            this.Attack20Button.Text = "Attack = 20";
            this.Attack20Button.UseVisualStyleBackColor = true;
            // 
            // Attack30Button
            // 
            this.Attack30Button.AutoSize = true;
            this.Attack30Button.Location = new System.Drawing.Point(2, 74);
            this.Attack30Button.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Attack30Button.Name = "Attack30Button";
            this.Attack30Button.Size = new System.Drawing.Size(80, 17);
            this.Attack30Button.TabIndex = 2;
            this.Attack30Button.TabStop = true;
            this.Attack30Button.Text = "Attack = 30";
            this.Attack30Button.UseVisualStyleBackColor = true;
            // 
            // AddAttributesButton
            // 
            this.AddAttributesButton.Location = new System.Drawing.Point(76, 30);
            this.AddAttributesButton.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.AddAttributesButton.Name = "AddAttributesButton";
            this.AddAttributesButton.Size = new System.Drawing.Size(152, 66);
            this.AddAttributesButton.TabIndex = 3;
            this.AddAttributesButton.Text = "Add Attributes";
            this.AddAttributesButton.UseVisualStyleBackColor = true;
            this.AddAttributesButton.Click += new System.EventHandler(this.AddAttributesButton_Click);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.Attack30Button);
            this.panel1.Controls.Add(this.Attack20Button);
            this.panel1.Controls.Add(this.Attack10Button);
            this.panel1.Location = new System.Drawing.Point(110, 135);
            this.panel1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(80, 95);
            this.panel1.TabIndex = 4;
            // 
            // AddAttributesScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(324, 356);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.AddAttributesButton);
            this.Name = "AddAttributesScreen";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Adding an attribute";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RadioButton Attack10Button;
        private System.Windows.Forms.RadioButton Attack20Button;
        private System.Windows.Forms.RadioButton Attack30Button;
        private System.Windows.Forms.Button AddAttributesButton;
        private System.Windows.Forms.Panel panel1;
    }
}