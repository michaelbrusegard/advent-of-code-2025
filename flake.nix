{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.05?shallow=1";
  };

  outputs = { self, nixpkgs }:
    let
      supportedSystems = [
        "x86_64-linux"
        "aarch64-linux"
        "aarch64-darwin"
      ];
      forAllSystems = nixpkgs.lib.genAttrs supportedSystems;
    in
    {
      devShells = forAllSystems (system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
        in
        {
          default = pkgs.mkShell {
            buildInputs = with pkgs; [
              gcc
              clang
              lldb
              valgrind
              clang-tools
            ];
          };
        });
    };
}
