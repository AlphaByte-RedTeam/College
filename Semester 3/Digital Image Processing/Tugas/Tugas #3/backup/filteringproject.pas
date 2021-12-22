unit FilteringProject;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    btnLoad: TButton;
    btnSave: TButton;
    btnProcess: TButton;
    Image1: TImage;
    Image2: TImage;
    radioGroupColor: TRadioGroup;
    radioGroupFilter: TRadioGroup;
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

end.

