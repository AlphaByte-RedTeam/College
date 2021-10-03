unit Utama;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TFormUtama }

  TFormUtama = class(TForm)
    btnLoad: TButton;
    btnSave: TButton;
    btnWarna: TButton;
    btnInvers: TButton;
    btnGray: TButton;
    btnBiner: TButton;
    btnBrightness: TButton;
    btnContrast: TButton;
    imgOriginal: TImage;
    imgEdited: TImage;
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

procedure TFormUtama.btnLoadClick(Sender: TObject);
begin
  if (openDialog.Execute) then
  begin

  end;
end;

end.

