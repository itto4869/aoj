_aoj_complete() {
  local cur prev
  COMPREPLY=()
  cur="${COMP_WORDS[COMP_CWORD]}"
  prev="${COMP_WORDS[COMP_CWORD - 1]}"

  local commands="b build r run d debug t test n new l list c clean help"

  if [[ "$COMP_CWORD" -eq 1 ]]; then
    COMPREPLY=($(compgen -W "$commands" -- "$cur"))
    return 0
  fi

  case "$prev" in
    b | build | r | run | d | debug | t | test)
      local problems
      problems="$(find problems -maxdepth 1 -type f -name '*.cpp' -printf '%f\n' 2>/dev/null | sed 's/\.cpp$//')"
      COMPREPLY=($(compgen -W "$problems" -- "$cur"))
      ;;
    *)
      COMPREPLY=()
      ;;
  esac
}

complete -F _aoj_complete aoj
complete -F _aoj_complete ./aoj
