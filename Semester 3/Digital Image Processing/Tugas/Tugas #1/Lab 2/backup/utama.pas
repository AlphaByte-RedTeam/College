unit Utama;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TFormUtama }

  TFormUtama = class(TForm)
    btnLoad: TButton;
    btnWarna: TButton;
    btnRed: TButton;
    btnGreen: TButton;
    btnBlue: TButton;
    btnGray: TButton;
    imgOriginal: TImage;
    openDialog: TOpenDialog;
    saveDialog: TSaveDialog;
    procedure btnLoadClick(Sender: TObject);
  private

  public

  end;

var
  FormUtama: TFormUtama;

implementation

{$R *.lfm}


{ TFormUtama }

uses Windows;

var
  bmpR, bmpG, bmpB : array[0..1000, 0..1000] of byte;

procedure TFormUtama.btnLoadClick(Sender: TObject);
var
  x, y : integer;
begin
  if openDialog.Execute then
  begin
    imgOriginal.Picture.LoadFromFile(openDialog.FileName);
    for y:=0 to imgOriginal.Height-1 do
    begin
      for x:=0 to imgOriginal.Width-1 do
      begin
        bmpR[x, y] := getRValue(imgOriginal.Canvas.Pixels[x, y]);
      end;
    end;
  end;
end;

end.

